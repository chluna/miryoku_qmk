# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

# Add Custom shift keys
# https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
SRC += features/custom_shift_keys.c

# Add X-Case
# https://github.com/andrewjrae/kyria-keymap#x-case
SRC += features/casemodes.c

# Customize Miryoku
MIRYOKU_ALPHAS = QWERTY
MIRYOKU_EXTRA = COLEMAKDH
MIRYOKU_TAP = QWERTY
MIRYOKU_MAPPING = EXTENDED_THUMBS
MIRYOKU_NAV = INVERTEDT
MIRYOKU_CLIPBOARD = WIN

# QMK features
AUTO_SHIFT_ENABLE = no
COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no
DYNAMIC_TAPPING_TERM_ENABLE = yes
OS_DETECTION_ENABLE = yes
