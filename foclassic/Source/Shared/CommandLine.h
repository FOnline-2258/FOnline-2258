/////
//
// FOClassic v@FOCLASSIC_VERSION@
// Timestamp @EXTENSIONS_CONTENT_TIMESTAMP@
//
/////

#ifndef __COMMAND_LINE__
#define __COMMAND_LINE__

#include <string>
#include <vector>

class CmdLine
{
protected:
    std::vector<std::string> Cache;

public:
    // copy of argv[0]
    const std::string App;

    #if !defined (FOCLASSIC_EXTENSION)
    CmdLine( int argc, char** argv );
    ~CmdLine();
    #endif

    virtual std::string Get();
    virtual std::string GetArg( unsigned int arg );

    virtual bool IsOption( const std::string& option );
    virtual bool IsOptionEmpty( const std::string& option );

    virtual int                      GetInt( const std::string& option, const int& default_value, const unsigned char& base = 10 );
    virtual std::string              GetStr( const std::string& option );
    virtual std::string              GetStr( const std::string& option, const std::string& default_value );
    virtual std::vector<std::string> GetStrVec( const std::string& option, char separator );
};

#if !defined (FOCLASSIC_EXTENSION)
extern CmdLine* CommandLine;
#endif

#endif // __COMMAND_LINE__ //
