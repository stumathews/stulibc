#include <logging.h>
#include <assert.h>
#include <files.h>
#include <string.h>
#include <testing.h>
void test_LOG_If()
{
  int condition = 1 > 0;

  LOG_If( condition, "It works");

  assert( FILE_Exists( LOG_GetDefaultLogFileName() ));
}

void test_LOG_Log()
{
  LOG_Log("hello");
  assert( FILE_Exists( LOG_GetDefaultLogFileName() ));
  
}

void test_LOG_LogToStream()
{
  char* filename = "filename.txt";
  FILE* stream = fopen(filename, "w");

  assert( stream != NULL );
  LOG_LogToStream("message", stream);  
  
  stream = freopen( filename, "r", stream);
 
   // read from stream for message
  assert( FILE_ContainsString( stream, "message" ));
  
  fclose(stream);
  FILE_Delete(filename);
}

void test_LOG_DeleteLog()
{
  FILE_Delete( LOG_GetDefaultLogFileName());
  assert( !FILE_Exists( LOG_GetDefaultLogFileName() ));
  LOG_Log("Hello");
  assert( FILE_Exists( LOG_GetDefaultLogFileName() ));
  LOG_DeleteLog();
  assert( !FILE_Exists( LOG_GetDefaultLogFileName() ));
}

void test_LOG_GetDefaultLogFileName()
{
 assert(strlen( LOG_GetDefaultLogFileName()) >0);
}

int main( int argc, char** argv)
{
  struct TestDefinition tests[] = {
  TEST(test_LOG_If),
  TEST(test_LOG_Log),
  TEST(test_LOG_LogToStream),
  TEST(test_LOG_DeleteLog),
  TEST(test_LOG_GetDefaultLogFileName),
  };
  
  RUN_TESTS(tests);  

  LOG_DeleteLog();
  return 0;
}
