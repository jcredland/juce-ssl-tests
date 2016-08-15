/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

using std::cout;

void testConnection(URL url)
{
    cout << url.toString(true) << "\n";

    int statusCode;

    StringPairArray responseHeaders;
    ScopedPointer<InputStream> stream = url.createInputStream(false, nullptr, nullptr, String::empty, 4000, &responseHeaders, &statusCode);

//    MemoryBlock block(1000);
//    if (stream)
//        stream->readIntoMemoryBlock(block);

    if (stream)
        cout << "* OK, status code:" << statusCode << "\n";
    else
        cout << "* FAIL, status code:" << statusCode << "\n";

    cout << "\n";
}


int main (int argc, char* argv[])
{

    cout << SystemStats::getOperatingSystemName() << "\n";
    cout << "HTTPS Behaviour Testing" << "\n";
    cout << "Expect: OK\n";
    testConnection(URL("https://badssl.com/"));

    cout << "---Expect: STRONG FAIL\n";
    testConnection(URL("https://self-signed.badssl.com/"));

    cout << "---Expect: STRONG FAIL\n";
    testConnection(URL("https://untrusted-root.badssl.com/"));

    cout << "---Expect: FAIL (expired cert)\n";
    testConnection(URL("https://expired.badssl.com/"));

    cout << "---Expect: FAIL (rubbish cipher)\n";
    testConnection(URL("https://rc4.badssl.com/"));

    cout << "---Expect: FAIL (rubbish security setting)\n";
    testConnection(URL("https://dh480.badssl.com/"));

    return 0;
}
