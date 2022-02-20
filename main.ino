#include <FastLED.h>

#define LED_INT_PIN 3

#define LED_PIN 2
#define NUM_LEDS 64

#define RING_LED_PIN 4
#define RING_NUM_LEDS 16

#define BRIGHTNESS 64
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 10
#define DIRECTION 0 // lr 0, rl 1

#define NUM_FACES 10

CRGB leds[NUM_LEDS];
CRGB ring_leds[RING_NUM_LEDS];
CRGBPalette16 currentPalette;
TBlendType currentBlending;

// * Pre-defined facial expressions
typedef struct face
{
    const uint16_t exp[64];
    const uint8_t cnt;
} Face;

const Face _ring = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    16
};

const Face smile = {
    //{60, 50, 46, 33, 30, 17, 13, 3},
    {13, 12, 11, 10, 17, 22, 31, 24},
    8
};

const Face sad = {
    //{60, 52, 42, 37, 26, 21, 11, 3},
    {31, 24, 33, 38, 45, 44, 43, 42},
    8
};

const Face surprise = {
    //{44, 45, 33, 36, 27, 30, 19, 18},
    {12, 11, 18, 21, 29, 26, 35, 36},
    8
};

const Face heart = {
    //{53, 52, 51, 45, 41, 37, 33, 30, 26, 22, 18, 12, 11, 10},
    {12, 11, 18, 21, 30, 25, 33, 38, 46, 44, 43, 41, 50, 53},
    14
};

const Face okay = {
    //{62, 61, 60, 51, 49, 46, 45, 44, 30, 29, 28, 27, 26, 25, 24, 19, 13, 11, 5, 1},
    {15, 14, 13, 11, 8, 16, 18, 20, 22, 31, 30, 29, 27, 26, 36, 38, 43, 40, 52, 59},
    20
};

const Face question = {
    //{41, 39, 31, 29, 28, 24, 22, 21, 20},
    {4, 20, 27, 37, 42, 50, 53, 60, 59},
    9
};

const Face x = {
    //{54, 49, 45, 42, 36, 35, 28, 27, 21, 18, 14, 9},
    {14, 9, 18, 21, 28, 27, 35, 36, 45, 42, 49, 54},
    12
};

const Face exclamation = {
    //{31, 29, 28, 27, 26, 25, 24},
    {4, 20, 27, 36, 43, 52, 59},
    7
};

const Face spicy = {
    //{61, 60, 59, 58, 57, 54, 52, 43, 41, 29, 28, 27, 26, 25, 18, 13, 12, 11, 10, 9},
    {16, 20, 21, 22, 31, 27, 25, 32, 33, 34, 36, 38, 47, 43, 41, 48, 49, 50, 52, 54},
    20
};

const Face tired = {
    //{60, 59, 58, 54, 52, 43, 40, 39, 36, 27, 24, 23, 20, 11, 9, 5, 4, 3},
    {31, 24, 32, 33, 34, 35, 36, 37, 38, 39, 47, 40, 49, 54, 61, 60, 59, 58
    },
    18
};

Face face_list[NUM_FACES] = {smile, sad, surprise, heart, okay, question, x, exclamation, spicy, tired};
int face_tracker = 0;
unsigned long last_interrupt_time = 0;

void setup()
{
    delay(3000); // power-up safety delay

    pinMode(LED_INT_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(LED_INT_PIN), _LED_SWAP, RISING);

    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, RING_LED_PIN, COLOR_ORDER>(ring_leds, RING_NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);

    currentPalette = RainbowColors_p;
    // currentPalette = PartyColors_p;
    currentBlending = LINEARBLEND;
    // currentBlending = NOBLEND;
}

void loop()
{
    // ChangePalettePeriodically();

    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */

    resetLEDs();
    FillLEDsFromPaletteColors(startIndex, ring_leds, _ring);
    FillLEDsFromPaletteColors(startIndex, leds, face_list[face_tracker]);

    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void FillLEDsFromPaletteColors(uint8_t colorIndex, CRGB *led_list, const Face &expression)
{
    for (int i = 0; i < expression.cnt; i++)
    {
        if (DIRECTION == 0)
        {
            led_list[expression.exp[(expression.cnt - 1 - i)]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
        }
        else
        {
            led_list[expression.exp[i]] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
        }
        colorIndex += 3;
    }
}

void resetLEDs()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = ColorFromPalette(currentPalette, CRGB::Black, 0, currentBlending);
    }
}

void _LED_SWAP() {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > 200) {
        face_tracker += 1;
        if (face_tracker == NUM_FACES) {
            face_tracker = 0;
        }
    }
    last_interrupt_time = interrupt_time;
}