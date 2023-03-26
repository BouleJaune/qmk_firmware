# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/Uq7gcHh)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a fork of QMK official repos that I use for my own keyboards and keymaps.

## Keymaps

* [Corne colemak](/keyboards/crkbd/keymaps/BouleJaune)

## How to compile and flash

Elite-C board use dfu bootloader and pro-micro uses caterina, so the commands varies if you have different boards for each half like I do.

For Elite-C :
``qmk flash -kb crkbd -km BouleJaune -bl dfu``

For Pro-micro :
``qmk flash -kb crkbd -km BouleJaune -bl avrdude``

## To do

Script to dynamically create images for the layout

Add Shoc board, and first custom pcb custom board to qmk

For crkbd: options (tapping terms, etc), layers (symbols specifically), resolder leds and screen, add new layers to screen...

## Documentation

* [Official repo](https://github.com/qmk/qmk_firmware)
* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)
