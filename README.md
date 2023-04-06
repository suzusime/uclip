# uclip
*clip.exe alternative for UTF-8 strings*

This copies UTF-8 strings from STDIN to the clipboard.

## Usage
### From WSL
```bash
wget https://github.com/suzusime/uclip/releases/download/v0.1.0/uclip.exe
chmod +x uclip.exe

sample=$(curl -s https://raw.githubusercontent.com/muan/unicode-emoji-json/v0.5.0/data-by-emoji.json | head -n10)
echo $sample

# ⚠ produce mojibake
echo $sample | clip.exe

# 😊 copied correctly
echo $sample | ./uclip.exe
```
