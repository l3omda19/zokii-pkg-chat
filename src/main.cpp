#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
 * Zokii Chat application core.
 *
 * The networking/UI layer is intentionally kept separate so a server address
 * can be configured later without embedding credentials in the binary.
 */

static char last_message[256];
static uint32_t message_count = 0;

extern "C" int zokii_chat_add_message(const char* msg)
{
    if (!msg) return -1;

    size_t n = strlen(msg);
    if (n >= sizeof(last_message))
        n = sizeof(last_message) - 1;

    memcpy(last_message, msg, n);
    last_message[n] = '\0';
    ++message_count;
    return (int)n;
}

extern "C" uint32_t zokii_chat_message_count()
{
    return message_count;
}

extern "C" const char* zokii_chat_last_message()
{
    return last_message;
}

int main()
{
    /*
     * Keep the process alive. The PS4 homebrew build system supplies the
     * platform runtime. This is the executable entry point that becomes
     * eboot.bin and then the PKG.
     */
    zokii_chat_add_message("Zokii Chat starting...");
    for (;;)
    {
        /* The UI/network implementation is added here in the next stage. */
        asm volatile("pause");
    }

    return 0;
}
