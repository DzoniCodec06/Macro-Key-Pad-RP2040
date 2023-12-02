import board

from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.handlers.sequences import simple_key_sequence
from kmk.handlers.sequences import send_string
from kmk.scanners import DiodeOrientation
from kmk.modules.layers import Layers


keyboard = KMKKeyboard()

keyboard.modules.append(Layers())

keyboard.col_pins = (board.GP29, board.GP28, board.GP27, board.GP26)
keyboard.row_pins = (board.GP6, board.GP5, board.GP4)
keyboard.diode_orientation = DiodeOrientation.COL2ROW

#KEY_SEQUENCE = ( (KC.LALT(), KC.TAB,) )

#ALT_TAB = simple_key_sequence (KEY_SEQUENCE)

DELAY = 1000 # Delay between sending string and hitting Enter

# ---- Apps commands ---- #

GITHUB = simple_key_sequence(
    (
        send_string("github.com"),
        KC.ENTER,
    )
)

GMAIL = simple_key_sequence(
    (
        send_string("gmail.com"),
        KC.ENTER,
    )
)

YOUTUBE = simple_key_sequence(
    (
        send_string("youtube.com"),
        KC.ENTER,
    )
)

FIGMA = KC.LCTRL(KC.LALT(KC.LSHIFT(KC.F)))

VS_CODE = KC.LCTRL(KC.LALT(KC.LSHIFT(KC.V)))

BROWSER = simple_key_sequence(
    (
        KC.LCTRL(KC.LALT(KC.LSHIFT(KC.B))),
        KC.MACRO_SLEEP_MS(DELAY),
        KC.LWIN(KC.UP)
    )
)

EASY_EDA = KC.LCTRL(KC.LALT(KC.LSHIFT(KC.E)))

FILES = KC.LWIN(KC.E)

NEXT = simple_key_sequence(
    (
        KC.LALT(no_release=True), 
        KC.MACRO_SLEEP_MS(30),
        KC.TAB,
        KC.MACRO_SLEEP_MS(30),
        KC.LALT(no_press=True),
    )
)

STEAM = KC.LCTRL(KC.LSHIFT(KC.LALT(KC.S)))

# ---- Functions commands ---- #

EXIT = KC.LALT(KC.F4)

SAVE = simple_key_sequence(
    (
        KC.LCTRL(no_release=True),
        KC.S,
        KC.LCTRL(no_press=True)
    )
)

NEW_TAB = KC.RCTRL(KC.T)

CLOSE_TAB = KC.RCTRL(KC.W)

RELOAD_TAB = KC.RCTRL(KC.R)

SWITCH_TAB = KC.RCTRL(KC.TAB)

INSPECT_EL = KC.F12

OPEN_FOLDER = simple_key_sequence(
    (
        KC.LCTRL(no_release=True),
        KC.K,
        KC.O,
        KC.LCTRL(no_press=True)
    )
)

# ---- Layers ---- #

LAYER_TOGGLE = KC.LT(1, SAVE) 

BROWSER_LAYER = KC.TG(2)

# ---- Keymap ---- #

keyboard.keymap = [
    [
        VS_CODE, FIGMA, EASY_EDA, KC.NO,
        NEXT, BROWSER, FILES, EXIT,
        KC.NO, KC.NO, LAYER_TOGGLE, KC.NO,
    ],

    [
        KC.NO, BROWSER_LAYER, KC.NO, KC.NO,
        KC.NO, KC.NO, KC.NO, KC.NO, 
        KC.NO, KC.NO, KC.NO, KC.NO, 
    ],      

    [
        NEW_TAB, CLOSE_TAB, RELOAD_TAB, SWITCH_TAB,
        KC.TAB, GITHUB, YOUTUBE, KC.ENTER,
        BROWSER_LAYER, INSPECT_EL, GMAIL, KC.NO,
    ]                                                             
]

if __name__ == '__main__':
    keyboard.go()
