# A keymap for xwhatsit/brand_new_model_f/f62/$(CONTROLLER)

- These F62's do not have a split backspace or right shift.
- The `wcass` version should always be used for these F62's.
- This is intended for use with the xwhatsit controller, with an atmega32u2 chip
- The pandrew utility can be used to put the xwhatsit into bootloader mode easily. See "Further Documentation" for more.

Flash instructions:
- Build with: `make xwhatsit/brand_new_model_f/f62:kuresov_ansi_regular_shift_regular_backspace`
- Use the Pandrew utility to put the board in bootloader mode
- If on Windows, use qmk-toolbox with the output file and `atmega32u2`

Further Documentation:
- https://www.modelfkeyboards.com/manual/
  - All instructions
  - Pandrew bootloader utility
- https://docs.google.com/document/d/1B6YmmtUdpv2B6bOzcFxsA5DRG1vhqfTOyTfg2hbOB90/edit
  - Additional instructions including information about Pandrew's repo
