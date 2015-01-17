#include <cmdline.h>
#include <testing.h>
#include <debugging.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <assert.h>

bool help_function_ran_ok = false;
bool exitf_function_ran_ok = false;
bool name_function_ran_ok = false;
bool setit2_function_ran_ok = false;
bool part1_function_ran_ok = false;
bool needvaluearg_function_ran_ok = false;

void help(char* value)
{
 if( STR_IsNullOrEmpty(value) )
 {    
  help_function_ran_ok = true;
 }
}

void exitf(char* value)
{
    DBG("Im the handler function for exitf(), arg is %s\n",value);
    exitf_function_ran_ok = true;
}
void name(char* value)
{
    DBG("Im the handler function for name(), arg is %s\n",value);
    name_function_ran_ok = true;

}
void setit2(char* value)
{
    DBG("Im the handler function for setit2, arg is %s\n",value);
    setit2_function_ran_ok = true;
}
void part1(char* value)
{
    DBG("Im the handler function for part1(),arg is %s\n",value);
    part1_function_ran_ok = true;
}

void needvaluearg(char* value)
{
    if( !STR_IsNullOrEmpty(value)) {
        needvaluearg_function_ran_ok = true;
    }
}


struct Argument* createNewArgument( char* name, char* description, bool isMandatory, bool isValueMandatory, void (*handler)(char* arg))
{
    struct Argument* newArgument = (struct Argument*) malloc( sizeof(struct Argument) );
    strcpy(newArgument->name,name);
    strcpy(newArgument->description,description);
    newArgument->isMandatory = isMandatory;
    newArgument->isValueMandatory = isValueMandatory;
    newArgument->handler = handler;
    return newArgument;
}

void test_CMD_AddArgument()
{
    struct Argument* arg1 = createNewArgument("help", "Print usage", false, false, help); // name, description, isMandatory, isValueMandatory
    struct Argument* arg2 = createNewArgument("exit", "Exit the application", false, false, exitf);
    struct Argument* arg3 = createNewArgument("name", "provide a name", true, true, name);
    struct Argument* arg4 = createNewArgument("setit2", "set it", true, true, setit2);
    struct Argument* arg5 = createNewArgument("part1", "setup part one to something", true, true, part1);
    struct Argument* arg6 = createNewArgument("needvaluearg", "setup part one to something", true, true, needvaluearg);


    CMD_AddArgument(arg1);
    CMD_AddArgument(arg2);
    CMD_AddArgument(arg3);
    CMD_AddArgument(arg4);
    CMD_AddArgument(arg5);
    CMD_AddArgument(arg6);


}
void test_CMD_AddArguments()
{
    //CMD_AddArguments( &arguments );
}
void test_CMD_Parse()
{
DBG("In test_CND_Parse\n");

    char* arguments[] = {"--help","-exit","/name=1","-setit2=one","-part1","part1_answer","--needvaluearg","",NULL};

    int num_args = 0;
    for( num_args = 0; arguments[num_args] != NULL; num_args++);
    ;

DBG("just before Parse()\n");
    CMD_Parse(num_args,arguments);

DBG("just after Parse\n");
    assert(help_function_ran_ok == true);
    assert(exitf_function_ran_ok == true);
    assert(name_function_ran_ok == true);
    assert(setit2_function_ran_ok == true);
    assert(part1_function_ran_ok == true);
    assert(needvaluearg_function_ran_ok == false); // we dont expect this function to run as no argument is provided
}

int main(int argc, char* argv[])
{
    struct TestDefinition tests[] = { test_CMD_AddArguments, "test_CMD_ADDArguments",
        test_CMD_AddArgument, "test_CMD_ADDArgument",
        test_CMD_Parse, "test_CMD_Parse"
    };
    run_tests(tests,3);

    CMD_Uninit();
    return 0;
}
