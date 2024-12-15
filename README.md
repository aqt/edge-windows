# Edge windows

## What

Creates a 1px wide frame at the sides of the monitor.

## Why

VMWare Workstation locks the mouse cursor to the VM when there is a borderless fullscreen window. Maybe it's caused by the specific application I am running inside but I doubt it. Either way, creating these windows provides a way for the mouse to escape the VM without having to press the release hotkey.

## Compile

```
g++.exe -s -o edge-windows.exe main.cpp
```
