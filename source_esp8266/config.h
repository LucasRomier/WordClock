// define pins
#define NEOPIN 16 // connect to DIN on NeoPixel
#define LED_TYPE WS2812B

#define STASSID "AMIV"
#define STAPSK "#pommespanda#"

// Timezone
#define _TIMEZONE TZ_Europe_Berlin // it is string value
#define _NTP_SERVER "pool.ntp.org"

// LED color setting
#define _COLORMODE "Rainbow" // Rainbow or RGB
#define _COLORR 44 // 0-255
#define _COLORG 255 // 0-255
#define _COLORB 59 // 0-255
#define _INTERVAL 100 // controls rainbow color shifting speed ms

// brightness based on time of day
#define _DAYBRIGHTNESS 180 // 0-200 
#define _NIGHTBRIGHTNESS 90 // 0-200

// cutoff times for day / night brightness. feel free to modify.
#define _MORNINGCUTOFF 7 // when does daybrightness begin? 7am
#define _NIGHTCUTOFF 22 // when does nightbrightness begin? 10pm

// show AMPM
#define _SHOWAMPM "enable" // "enable" or "disable"

// show seconds
#define _SHOWSECONDS "false" // "enable" or "disable"

// show minuts
#define _SHOWMINUTES "false" // "enable" or "disable"

#define setMask(word) xsetMask(word,sizeof(word),1) // set mask 1
#define resetMask(word) xsetMask(word,sizeof(word),0) // set mask 0

// global variables
CRGB leds[NUM_LEDS];
const uint8_t NUM_MAP = sizeof(LED)/sizeof(LED[0]); // number of mapping elements
uint8_t mask[NUM_MAP]; // LEDs ON/OFF
uint r_count = 0; // an integer for the color shifting effect
unsigned long r_millis = millis(); 
const char* ssid = STASSID;  // your network SSID (name)
const char* pass = STAPSK;   // your network password
static time_t current; // This are the seconds since Epoch (1970) - UTC