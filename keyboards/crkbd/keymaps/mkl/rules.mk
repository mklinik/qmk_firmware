MOUSEKEY_ENABLE = yes    # Mouse keys
RGBLIGHT_ENABLE = no    # Enable WS2812 RGB underlight.
OLED_ENABLE     = no
OLED_DRIVER     = SSD1306
# link-time optimization shrinks the image
LTO_ENABLE      = yes
CAPS_WORD_ENABLE = yes

# I have trouble with the n-key, let's try this
# Doesn't work. I removed the ball from the key, seems to work better
DEBOUNCE_TYPE = sym_defer_g
