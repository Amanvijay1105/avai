#!/bin/bash

mkdir -p ~/Downloads/Images
mkdir -p ~/Downloads/Documents
mkdir -p ~/Downloads/Videos

mv ~/Downloads/*.jpg ~/Downloads/Images 2>/dev/null
mv ~/Downloads/*.png ~/Downloads/Images 2>/dev/null
mv ~/Downloads/*.pdf ~/Downloads/Documents 2>/dev/null
mv ~/Downloads/*.mp4 ~/Downloads/Videos 2>/dev/null

echo "Downloads organized."