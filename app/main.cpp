#include <iostream>
#include <stdio.h>
#include <zlib.h>
#include "ris.pb.h"
#include "t.h"
#include "SocketClass.h"

using namespace std;

int main(void)
{

   GOOGLE_PROTOBUF_VERIFY_VERSION;
   string ostring;
   char   buffer[1024];

   bool status;
   int  stat;
   ris::RisBuffer p1;
   ris::KeyValue kv;

   ServerSocket serv;
   serv.Init();
   serv.SetPort(31013);
   serv.SetTimeout(1.e10);
   stat = serv.Open();
   if ( stat != 0 )
   {
      printf("Can't open server socket %d\n", stat);
   }

   stat = serv.Read(buffer, sizeof(buffer));
   printf("Read %d bytes\n", stat);

   status = kv.IsInitialized();
   kv.CheckInitialized();
   if ( !status )
   {
      printf("not initialized\n");
      return -1;
   }

   dump(buffer, stat);

   status = kv.ParseFromArray(buffer, stat);
   printf("Parse returns %d\n", status);
   if ( !status )
   {
      return -2;
   }

   printf("Key   %s\n", kv.key().c_str());
   printf("Value %s\n", kv.value().c_str());

   //dump(p1.data().c_str(), p1.data().length());

   unsigned int crc =  crc32(0x00000000, (const unsigned char *)p1.data().c_str(), p1.data().length());
   printf("Calculated CRC %x\n", crc);

   t();

   printf("main done\n");
}
