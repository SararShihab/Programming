"""
extract_paper.py

Converts a research paper PDF into clean, token-efficient Markdown
for feeding into an LLM peer-review prompt.

Usage:
    python extract_paper.py input.pdf output.md
    python extract_paper.py input.pdf output.md --keep-appendix
    python extract_paper.py input.pdf output.md --keep-refs

Requires: pip install pymupdf4llm --break-system-packages
"""

import re
import sys
import argparse
import pymupdf4llm


# Section headings that mark the start of content we usually want to DROP.
# Matched case-insensitively at the start of a Markdown heading line.
DROP_SECTION_PATTERNS = [
    r"references",
    r"bibliography",
    r"acknowledg(e)?ments?",
    r"funding",
    r"conflicts? of interest",
    r"author contributions?",
    r"ethics statement",
    r"reproducibility statement",
]

APPENDIX_PATTERN = r"appendix"


def extract_markdown(pdf_path: str) -> str:
    """Extract the PDF to Markdown using PyMuPDF4LLM (preserves headings,
    tables, and reading order across multi-column layouts)."""
    md_text = pymupdf4llm.to_markdown(pdf_path)
    return md_text


def strip_repeated_headers_footers(text: str) -> str:
    """Remove common extraction artifacts: standalone page numbers,
    running headers/footers that repeat on every page."""
    lines = text.split("\n")
    cleaned = []
    for line in lines:
        stripped = line.strip()
        # Standalone page number lines (e.g. "12" or "Page 12")
        if re.fullmatch(r"(page\s*)?\d{1,4}", stripped, flags=re.I):
            continue
        # Common footer patterns: "arXiv:2401.01234v2 [cs.CL] 3 Jan 2024"
        if re.match(r"arxiv:\d{4}\.\d{4,5}", stripped, flags=re.I):
            continue
        cleaned.append(line)
    return "\n".join(cleaned)


def split_into_sections(text: str):
    """Split markdown into (heading, body) chunks based on '#' headings."""
    # Matches lines like "## 4.2 Ablation Studies"
    heading_re = re.compile(r"^(#{1,3})\s+(.*)$", re.MULTILINE)
    matches = list(heading_re.finditer(text))
    sections = []

    if not matches:
        return [("(no heading)", text)]

    # Preamble before first heading (title, authors, abstract sometimes)
    if matches[0].start() > 0:
        sections.append(("(preamble)", text[: matches[0].start()]))

    for i, m in enumerate(matches):
        heading = m.group(2).strip()
        start = m.end()
        end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
        body = text[start:end]
        sections.append((heading, m.group(0) + body))

    return sections


def should_drop(heading: str, keep_refs: bool, keep_appendix: bool) -> bool:
    h = heading.lower()
    if not keep_refs:
        for pat in DROP_SECTION_PATTERNS:
            if re.search(pat, h):
                return True
    if not keep_appendix and re.search(APPENDIX_PATTERN, h):
        return True
    return False


def clean_paper(pdf_path: str, keep_refs: bool = False, keep_appendix: bool = False) -> str:
    raw_md = extract_markdown(pdf_path)
    raw_md = strip_repeated_headers_footers(raw_md)

    sections = split_into_sections(raw_md)
    kept = []
    for heading, body in sections:
        if should_drop(heading, keep_refs, keep_appendix):
            continue
        kept.append(body)

    result = "\n".join(kept)

    # Collapse 3+ blank lines down to 2 (extraction sometimes leaves gaps)
    result = re.sub(r"\n{3,}", "\n\n", result)
    return result.strip()


def run(input_pdf: str, output_md: str, keep_refs: bool = False, keep_appendix: bool = False) -> str:
    """
    Notebook-friendly entry point — call this directly from a Jupyter cell:

        from extract_paper import run
        cleaned_text = run("paper.pdf", "paper_clean.md")

    Do NOT call main() in Jupyter — argparse reads sys.argv, which Jupyter
    fills with its own kernel arguments and will crash or misbehave.

    Returns the cleaned text (also written to output_md).
    """
    cleaned = clean_paper(input_pdf, keep_refs=keep_refs, keep_appendix=keep_appendix)

    with open(output_md, "w", encoding="utf-8") as f:
        f.write(cleaned)

    orig_len = len(extract_markdown(input_pdf))
    new_len = len(cleaned)
    saved_pct = 100 * (1 - new_len / orig_len) if orig_len else 0
    print(f"Extracted: {output_md}")
    print(f"Original chars: {orig_len:,} | Cleaned chars: {new_len:,} | Reduced by {saved_pct:.1f}%")

    return cleaned


def main():
    """CLI entry point — only for running as a terminal script:
    `python extract_paper.py paper.pdf paper_clean.md`
    """
    parser = argparse.ArgumentParser(description="Extract and clean a paper PDF to Markdown.")
    parser.add_argument("input_pdf")
    parser.add_argument("output_md")
    parser.add_argument("--keep-refs", action="store_true", help="Keep References/Bibliography section")
    parser.add_argument("--keep-appendix", action="store_true", help="Keep Appendix sections")
    args = parser.parse_args()

    run(args.input_pdf, args.output_md, keep_refs=args.keep_refs, keep_appendix=args.keep_appendix)


if __name__ == "__main__":
    main()