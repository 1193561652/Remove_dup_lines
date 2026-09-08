// Qt translation of the original Main.Selection command by G. Singh.
#include <Plugin.h>
#include "RemoveDuplicatesCore.h"
using namespace QtPlugin;
namespace {
void selection(void*) {
    sci(SCI_TARGETFROMSELECTION);
    auto input = targetText();
    if (input.isEmpty()) { error("Remove Duplicate lines", "please select lines first"); return; }
    auto output = removeDuplicateLines(QString::fromUtf8(input)).toUtf8();
    if (input == output) { sci(SCI_CLEARSELECTIONS); return; }
    sci(SCI_REPLACESEL,0,reinterpret_cast<intptr_t>(output.constData()));
}
void showAbout(void*) { about("Remove Duplicate lines", "To Remove all visible Duplicate lines Remove Whitespace first\nEdit > Blank Operations > Trim Trailing Space\n\nRemove Duplicate lines Except Empty lines\nbuild by G. Singh\n29-10-2019 build 1.3.0.2"); }
void setup() {
    add("Remove duplicate lines",invoke<selection>);
    add("---",nullptr); add("---",nullptr);
    add("About",invoke<showAbout>);
}
void notify(const NppPluginNotification*) {}
}
NPP_QT_EXPORTS("Remove Duplicate lines", setup, notify)
