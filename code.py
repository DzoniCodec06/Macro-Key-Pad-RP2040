import board
import digitalio

from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.handlers.sequences import simple_key_sequence
from kmk.scanners import DiodeOrientation


keyboard = KMKKeyboard()

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT
led.value = True

keyboard.col_pins = (board.GP21, board.GP13, board.GP16)
keyboard.row_pins = (board.GP19,)
keyboard.diode_orientation = DiodeOrientation.COL2ROW

led = digitalio.DigitalInOut(board.GP15)
led.direction = digitalio.Direction.OUTPUT
led.value = True

#KEY_SEQUENCE = ( (KC.LALT(), KC.TAB,) )

#ALT_TAB = simple_key_sequence (KEY_SEQUENCE)


keyboard.keymap = [
    [KC.A, KC.BSPACE, KC.C]                                                                   
]

if __name__ == '__main__':
    keyboard.go()
