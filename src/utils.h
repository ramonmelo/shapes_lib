// NameOf Function
#define NAMEOF(x) #x
//#define printvar(x) nameof(x)

// File Info Macro
#define COMPILE_HEADER __FILE__ << ":" << __DATE__

// "Delegates"
using SimpleFunc = int (*)(int);

// Friends classes for testing purposes