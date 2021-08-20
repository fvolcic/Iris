//This is for selecting what type of LED lights the user will be using.
#define APA102_LEDS

// Define which core is used for what tasks.
#define LED_CORE 1
#define ALT_CORE 0

// Define which pins to use to control the led strip.
#ifdef APA102_LEDS
    #define DATAPIN 14
    #define CLOCKPIN 12
#endif

#define MAX_MESSAGE_LENGTH 2048 // Max network message size - 2KB. 

// Your secret key. Do not share. Generate with -> $ openssl rand -hex 8
#define SECRET_KEY {0x23,}

#define VERBOSE // print information via serial. 
#define VERBOSITY_LEVEL // The level of verbosity for print statements
#define BAUD 115200

// Information regaurding program debugging.
#define DEBUG_LED_MODE
#ifdef DEBUG_LED_MODE
#define SSID "SSID-HERE"
#define PASS "PASS-HERE"
#endif