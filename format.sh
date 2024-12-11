awk '
{
    # Detect if the line matches the desired pattern
    if (match($0, "[^ ]                                 ")) {
        gap_pos = RSTART  # Position of the gap
        first_half = substr($0, 1, gap_pos - 0)
        second_half = substr($0, gap_pos + RLENGTH)

        # Trim trailing/leading spaces for both halves
        gsub(/[[:space:]]+$/, "", first_half)
        gsub(/^[[:space:]]+/, "", second_half)

        # Store the halves
        first_lines[++block_count] = first_half
        second_lines[block_count] = second_half
    } else {
        # Print non-matching lines immediately
        print $0
    }

    # When we have 5 lines in the current block, print and reset
    if (block_count == 5) {
        for (i = 1; i <= 5; i++) {
            print first_lines[i]
        }
        print ""
        for (i = 1; i <= 5; i++) {
          long = "                      "
          short = "             "
            if (second_lines[i] != "")
              if (i == 5)
                print short second_lines[i]
              else
                print long second_lines[i]
        }
        block_count = 0
    }
}
END {
    # Print remaining lines if block_count < 5
    if (block_count > 0) {
        for (i = 1; i <= block_count; i++) {
            print first_lines[i]
        }
        for (i = 1; i <= block_count; i++) {
            if (second_lines[i] != "")
                print "                      " second_lines[i]
        }
    }
}' pNroL/keymap.c >pNroL/keymap.tmp && mv pNroL/keymap.tmp pNroL/keymap.c

sed -i '' "s/LAYOUT_voyager/LAYOUT_LR/g" pNroL/keymap.c
sed -i '' "s/\[0\]/\[BASE\]/g" pNroL/keymap.c
sed -i '' "s/\[1\]/\[SYM\]/g" pNroL/keymap.c
sed -i '' "s/\[2\]/\[NUM\]/g" pNroL/keymap.c
sed -i '' "s/\[3\]/\[WIN\]/g" pNroL/keymap.c
sed -i '' "s/\[4\]/\[FUN\]/g" pNroL/keymap.c
sed -i '' "s/KC_MS_BTN1/KC_BTN1/g" pNroL/keymap.c
sed -i '' "s/KC_MEDIA_PLAY_PAUSE/KC_MPLY/g" pNroL/keymap.c
sed -i '' "s/KC_QUOTE/KC_QUOT/g" pNroL/keymap.c
sed -i '' "s/KC_ENTER/KC_ENT/g" pNroL/keymap.c
sed -i '' -EH "s/KC_KP_PLUS(,?)/KC_PPLS\1   /g" pNroL/keymap.c
sed -i '' -EH "s/KC_KP_MINUS(,?)/KC_PMNS\1    /g" pNroL/keymap.c
sed -i '' -EH "s/KC_KP_SLASH(,?)/KC_PSLS\1    /g" pNroL/keymap.c
sed -i '' -EH "s/KC_KP_ASTERISK(,?)/KC_PAST\1       /g" pNroL/keymap.c
sed -i '' -EH "s/KC_KP_COMMA(,?)/KC_PCMM\1    /g" pNroL/keymap.c
sed -i '' -EH "s/KC_KP_DOT(,?)/KC_PDOT\1  /g" pNroL/keymap.c

sed -i '' "s/KC_TRANSPARENT,/_______,       /g" pNroL/keymap.c
sed -i '' "s/KC_TRANSPARENT/_______/g" pNroL/keymap.c
sed -i '' "s/KC_NO,  /XXXXXXX,/g" pNroL/keymap.c
sed -i '' "s/KC_NO/XXXXXXX/g" pNroL/keymap.c

sed -i '' "s/LEFT_GUI,/LGUI,    /g" pNroL/keymap.c
sed -i '' "s/LEFT_ALT,/LALT,    /g" pNroL/keymap.c
sed -i '' "s/LEFT_SHIFT,/LSFT,      /g" pNroL/keymap.c
sed -i '' "s/LEFT_CTRL,/LCTL,     /g" pNroL/keymap.c

sed -i '' "s/TO(0),   /TO(BASE),/g" pNroL/keymap.c

sed -i '' -EH "s/[LR]GUI(\(.+?\),)/G\1   /g" pNroL/keymap.c
sed -i '' -EH "s/[LR]SFT(\(.+?\),)/S\1   /g" pNroL/keymap.c
sed -i '' -EH "s/[LR]ALT(\(.+?\),)/A\1   /g" pNroL/keymap.c
sed -i '' -EH "s/[LR]CTL(\(.+?\),)/C\1   /g" pNroL/keymap.c

sed -i '' -EH "s/AUDIO_//g" pNroL/keymap.c

sed -i '' -EH "s/VOL_DOWN(,?)/VOLD\1        /g" pNroL/keymap.c
sed -i '' -EH "s/VOL_UP(,?)/VOLU\1  /g" pNroL/keymap.c
sed -i '' -EH "s/SPACE/SPC/g" pNroL/keymap.c
sed -i '' -EH "s/ESCAPE(,?)/ESC\1   /g" pNroL/keymap.c
sed -i '' -EH "s/GRAVE(,?)/GRV\1  /g" pNroL/keymap.c
sed -i '' -EH "s/DELETE(,?)/DEL\1   /g" pNroL/keymap.c
sed -i '' -EH "s/RIGHT/RGHT /g" pNroL/keymap.c
sed -i '' -EH "s/MINUS(,?)/MINS\1 /g" pNroL/keymap.c
sed -i '' -EH "s/ASTERISK(,?)/ASTR\1    /g" pNroL/keymap.c
sed -i '' -EH "s/SLASH(,?)/SLSH\1 /g" pNroL/keymap.c
sed -i '' -EH "s/COMMA(,?)/COMM\1 /g" pNroL/keymap.c
sed -i '' -EH "s/RGB_MODE_FORWARD(,?)/UG_NEXT\1        /g" pNroL/keymap.c
sed -i '' -EH "s/PAGE_UP/PGUP/g" pNroL/keymap.c
sed -i '' -EH "s/EQUAL(,?)/EQL\1  /g" pNroL/keymap.c

sed -i '' -EH "s/,\s+$/,/g" pNroL/keymap.c
sed -i '' -EH "s/,        /, /g" pNroL/keymap.c
sed -i '' -EH "s/,(\s+)\s/\1, /g" pNroL/keymap.c
sed -i '' -EH "s/                                                    /                                                 /g" pNroL/keymap.c
