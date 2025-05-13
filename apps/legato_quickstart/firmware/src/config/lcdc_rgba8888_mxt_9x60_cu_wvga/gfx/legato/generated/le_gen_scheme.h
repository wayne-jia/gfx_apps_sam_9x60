#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme defaultScheme;
extern const leScheme BackScheme;
extern const leScheme ClearScheme;
extern const leScheme RadialGaugeScheme;
extern const leScheme EnabledScheme;
extern const leScheme DisabledScheme;
extern const leScheme StatsScheme;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

void legato_initialize_schemes(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_SCHEME_H
