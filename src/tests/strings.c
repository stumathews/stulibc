#include <strings.h>
#include <assert.h>
#include <testing.h>
#include <stulibc.h>

void test_append()
{
    char expected[] = "one two";
    int errors = 0;
    char* append_result = (char*) STR_AppendStrings( "one ", "two");

    if( append_result == NULL ) {
        // could not create buffer to store appended string
        errors++;
        exit(1);
    }

    if( strcmp( expected, append_result) != 0)
        errors++;

    if( errors ) exit(1);
}

void test_STR_Reverse()
{
    char beautiful[] = "BEAUTIFUL";
    STR_Reverse(beautiful);
    assert( strcmp("LUFITUAEB",beautiful) == 0 );
}

void test_STR_IsAlpha()
{
    char* alpha = "abcdefghijklmnopqstuvwxyz";
    char* nonalpha = "abcdefghijklmnopqstuvwxyz1";
    assert( STR_IsAlpha(alpha, strlen(alpha)));
    assert( !STR_IsAlpha(nonalpha, strlen(nonalpha)) );
}

void test_createString()
{
    int errors = 0;
    char* string1 = "string1";
    char* string2 = "string2";

    char* dynamic_string1 = STR_CreateString("string1");
    char* dynamic_string2 = STR_CreateString("string2");

    if( dynamic_string1 == NULL || dynamic_string2 == NULL ) errors++;
    if( errors ) exit(1);
    if( strcmp( string1, dynamic_string1 ) != 0) errors++;
    if( strcmp( string2, dynamic_string2 ) != 0) errors++;
    if( errors ) exit(1);
//    free( dynamic_string1);
  //  free( dynamic_string2);

}

void test_beginsWith()
{
    char* expected[] = {"--","-","/",NULL};
    char* inputs[] = {"--help","-help","/?",NULL};
    short MAX = 20;
    char input[MAX];

    for( int i = 0; inputs[i] != NULL; i++ ) {
        strncpy(input,inputs[i],MAX);
        assert( STR_BeginsWith( expected[i], inputs[i] ) == true );
        memset( input,'\0',MAX);
    }

}

void test_beginsWithEither()
{
    char* possibilities[] = {"--","-","/",NULL};
    assert( strcmp( STR_BeginsWithEither( possibilities, "--thanks" ), possibilities[0]) == 0 );
    assert( strcmp( STR_BeginsWithEither( possibilities, "-h"), possibilities[1]) == 0 );
    assert( strcmp( STR_BeginsWithEither( possibilities, "/?"), possibilities[2]) == 0 );
    assert( strcmp( STR_BeginsWithEither( possibilities, "a"), "") == 0);;
}


void test_IsNullOrEmpty()
{
    char* null_string = NULL;
    char* string1 = "hello";
    char* empty = "";
    assert( STR_IsNullOrEmpty("") == true );
    assert( STR_IsNullOrEmpty(null_string) == true);
    assert( STR_IsNullOrEmpty(string1) == false);
    assert( STR_IsNullOrEmpty(empty) == true );
}


void test_STR_Without()
{
    char* name = "Stuart Mathews";
    char* arg = "--help";
    short MAX = 20;
    char* buffer;

    buffer = STR_Without( " Mathews", name);
    assert( strcmp( buffer, "Stuart" ) == 0 );
    buffer = STR_Without( "--", arg);
    assert( strcmp( buffer, "help" ) == 0 );
    buffer = STR_Without("stuart","peter stuart mathews 1 stuart");

    char* test = "peter  mathews 1 ";
    assert( strcmp( buffer, test ) == 0 );
    buffer = STR_Without(",,","s,,t,,u,,a,,r,,t");
    assert( strcmp( buffer, "stuart" ) == 0 );
    buffer = STR_Without(",","s,t,u,a,r,t");
    assert( strcmp( buffer, "stuart" ) == 0 );
}

void test_STR_Contains()
{
    assert( STR_Contains("stuart","stuartmathews") == true );
    assert( STR_Contains("stuart","StuartMathews") == false );
    assert( STR_Contains("--","--help") == true);
    assert( STR_Contains("1234","1234567890") == true );
}
void test_STR_EndsWith()
{
    assert( STR_EndsWith("s","strings") == true);
    assert( STR_EndsWith("=","--name=") == true);
    assert( STR_EndsWith("=","--name=Stuart") == false );
    assert( STR_EndsWith("bracket","safteybracket") == true);
    assert( STR_EndsWith("fish","fishnchips") == false);
    assert( STR_EndsWith(" ","stuart ") == true);
    assert( STR_EndsWith("","stuart") == false);
}
void test_STR_FromLast()
{
    short MAX = 20;
    char buffer[MAX];

    assert( strcmp(STR_FromLast("=","name=stuart",buffer),"stuart") == 0 );
    assert( strcmp(STR_FromLast("a","name=stuart",buffer),"rt") == 0 );
    assert( strcmp(STR_FromLast("=","--name=stuart",buffer),"stuart") == 0 );
    assert( strcmp(STR_FromLast(" ","--setFlag boolean",buffer),"boolean") == 0 );
    assert( strcmp(STR_FromLast(",","Stuart, dammit",buffer),"dammit") != 0 );

}

int main(int argc, char** argv)
{
	LIB_Init();
    struct TestDefinition tests[] = {
        test_append,"test_append()",
        test_createString,"test_createString",
        test_beginsWith, "test_STR_BeginsWith",
        test_beginsWithEither, "test_STR_BeginsWithEither",
        test_IsNullOrEmpty,"test_STR_IsNullOrEmpty",
        test_STR_Without,"test_STR_Without",
        test_STR_Contains, "test_STR_Contains",
        test_STR_EndsWith, "test_STR_EndsWith",
        test_STR_FromLast, "test_STR_FromLast",
        test_STR_IsAlpha, "test_STR_IsAlpha",
        test_STR_Reverse, "test_STR_Reverse"
    };
    run_tests(tests,11);
    DBG("about to LIB_Unint()");
    LIB_Uninit();

    return 0;
};
