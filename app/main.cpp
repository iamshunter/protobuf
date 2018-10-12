#include <iostream>
#include <stdio.h>
#include "t1.pb.h"
#include "t.h"

using namespace std;


int main(void)
{

   GOOGLE_PROTOBUF_VERIFY_VERSION;
   string ostring;
   char   buffer[1024];

   t1::Person p1, p2;
   bool status;

   p1.set_id(21);
   p1.set_name("p1Name");
   printf("DebugString:\n%s", p1.DebugString().data() );

   status = p1.IsInitialized();
   p1.CheckInitialized();
   if ( !status )
   {
      printf("not initialized\n");
      return -1;
   }

   status = p1.SerializeToString(&ostring);
   printf("Serialize returns %d\n", status);
   if ( !status )
   {
      return -2;
   }
   dump(ostring.data(), ostring.length() );

   p1.set_id(12);
   printf("DebugString:\n%s", p1.DebugString().data() );
   p1.SerializeToString(&ostring);
   dump(ostring.data(), ostring.length() );

   memcpy(buffer, ostring.data(), ostring.length() );
   printf("Good status %d\n",   p2.ParseFromString(buffer) );
   printf("DebugString2 :\n%s", p2.DebugString().data() );

   buffer[3]++;
   buffer[3]++;
   printf("Bad status  %d\n", p2.ParseFromString(buffer) );
   p2.SerializeToString(&ostring);
   dump(ostring.data(), ostring.length() );
   printf("DebugString  :\n%s", p2.DebugString().data() );

   t();
   printf("main done\n");
}
