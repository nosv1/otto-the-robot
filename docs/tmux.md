# tmux cheat sheet

tmux 3.4, no `~/.tmux.conf`, so the prefix is the default **Ctrl+b**: press it, let go, then
press the key.

## Sessions

| | |
| --- | --- |
| `tmux new -s otto` | new session named otto |
| `tmux a -t otto` | reattach |
| `tmux ls` | list sessions |
| `C-b d` | detach (everything keeps running) |
| `tmux kill-session -t otto` | kill it |

## Panes

ROS: talker in one, listener in another.

| | |
| --- | --- |
| `C-b %` | split left/right |
| `C-b "` | split top/bottom |
| `C-b ←↑→↓` | move between panes |
| `C-b z` | zoom the pane (toggle) |
| `C-b x` | close the pane |
| `C-b Space` | cycle layouts |

## Windows (tabs)

| | |
| --- | --- |
| `C-b c` | new window |
| `C-b n` / `C-b p` | next / previous |
| `C-b 0-9` | jump to a window |
| `C-b ,` | rename |
| `C-b w` | pick from a list |

## Scrolling

| | |
| --- | --- |
| `C-b [` | scroll mode (arrows/PgUp; `q` to quit) |

New panes start a fresh shell from `~/.bashrc`, so ROS is already sourced. Ctrl+C in a pane stops
only that pane's node.
