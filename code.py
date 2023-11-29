import board

from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.handlers.sequences import simple_key_sequence
from kmk.handlers.sequences import send_string
from kmk.scanners import DiodeOrientation


keyboard = KMKKeyboard()

keyboard.col_pins = (board.GP29, board.GP28, board.GP27, board.GP26)
keyboard.row_pins = (board.GP6, board.GP5, board.GP4)
keyboard.diode_orientation = DiodeOrientation.COL2ROW

#KEY_SEQUENCE = ( (KC.LALT(), KC.TAB,) )

#ALT_TAB = simple_key_sequence (KEY_SEQUENCE)

GITHUB = simple_key_sequence(
    (
        KC.LCTRL(KC.LALT(KC.LSHIFT(KC.B))),
        KC.MACRO_SLEEP_MS(500),
        send_string("github.com"),
        KC.ENTER,
        KC.LWIN(KC.UP)
    )
)

GMAIL = simple_key_sequence(
    (
        KC.LCTRL(KC.LALT(KC.LSHIFT(KC.B))),
        KC.MACRO_SLEEP_MS(500),
        send_string("gmail.com"),
        KC.ENTER,
        KC.LWIN(KC.UP)
    )
)

YOUTUBE = simple_key_sequence(
    (
        KC.LCTRL(KC.LALT(KC.LSHIFT(KC.B))),
        KC.MACRO_SLEEP_MS(500),
        send_string("youtube.com"),
        KC.ENTER,
        KC.LWIN(KC.UP)
    )
)

FIGMA = KC.LCTRL(KC.LALT(KC.LSHIFT(KC.F)))

VS_CODE = KC.LCTRL(KC.LALT(KC.LSHIFT(KC.V)))

BROWSER = simple_key_sequence(
    (
        KC.LCTRL(KC.LALT(KC.LSHIFT(KC.B))),
        KC.MACRO_SLEEP_MS(500),
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

EXIT = KC.LALT(KC.F4)

SAVE = simple_key_sequence(
    (
        KC.LCTRL(no_release=True),
        KC.S,
        KC.LCTRL(no_press=True)
    )
)

OPEN_FOLDER = simple_key_sequence(
    (
        KC.LCTRL(no_release=True),
        KC.K,
        KC.O,
        KC.LCTRL(no_press=True)
    )
)

keyboard.keymap = [
    [
        VS_CODE, FIGMA, EASY_EDA, GITHUB,
        BROWSER, YOUTUBE, GMAIL, NEXT,
        FILES, OPEN_FOLDER, SAVE, EXIT,
    ]                                                                   
]

if __name__ == '__main__':
    keyboard.go()