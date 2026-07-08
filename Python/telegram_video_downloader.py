import os
import re
from telethon import TelegramClient
from tqdm import tqdm

# ----------------------------
# YOUR API CREDENTIALS
# ----------------------------
api_id = api id
api_hash = "api hash"

client = TelegramClient("session", api_id, api_hash)


def clean_filename(name):
    return re.sub(r'[\\/*?:"<>|]', "_", name)


async def download_file(message, folder):
    file_size = message.file.size if message.file else 0
    progress = tqdm(
        total=file_size,
        unit="B",
        unit_scale=True,
        desc=f"Message {message.id}",
    )

    last = 0

    async def callback(current, total):
        nonlocal last
        progress.update(current - last)
        last = current

    await message.download_media(
        file=folder,
        progress_callback=callback,
    )

    progress.close()


async def main():

    dialogs = []

    print("\nYour Channels & Groups:\n")

    async for dialog in client.iter_dialogs():
        dialogs.append(dialog)
        print(f"{len(dialogs)-1:3d}  {dialog.name}")

    choice = int(input("\nEnter channel number: "))

    entity = dialogs[choice].entity
    channel_name = clean_filename(dialogs[choice].name)

    folder = os.path.join("Downloads", channel_name)
    os.makedirs(folder, exist_ok=True)

    count = 0

    async for message in client.iter_messages(entity, reverse=True):

        if message.video:

            filename = await message.download_media(file=folder)

            if filename:
                count += 1
                print(f"Downloaded: {os.path.basename(filename)}")

    print(f"\nFinished! Downloaded {count} videos.")


with client:
    client.loop.run_until_complete(main())