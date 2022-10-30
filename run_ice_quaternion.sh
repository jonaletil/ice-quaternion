#!/bin/bash

CONFIGDIR="`pwd`"
WORKSPACE=$(git rev-parse --show-toplevel)
SESSION=ice-quaternion
tmux="tmux -2 -q"

$tmux kill-server

$tmux has-session -t $SESSION
if [ $? -eq 0 ]; then
       echo "Session $SESSION already exists. Attaching to session."
       $tmux attach -t $SESSION
       exit 0;
fi

command -v tmux >/dev/null 2>&1 || { echo >&2 "tmux is not installed but required. Trying to install it..."; sudo apt-get install tmux; }

$tmux new-session -d -s $SESSION
$tmux new-window -a -t $SESSION iox-roudi

$tmux split-window -t 0 -v $WORKSPACE/ice-quaternion-publisher
$tmux split-window -t 1 -h $WORKSPACE/ice-quaternion-subscriber

$tmux attach -t $SESSION
