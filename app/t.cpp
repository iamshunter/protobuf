#include <stdio.h>
#include "ris.pb.h"
#include "t.h"

void dump(const char *data, int numChar)
{
   for ( int ii = 0; ii < numChar; ii++ )
   {
      if ( ii%16 == 0 )
      {
         printf("\n%4d) ", ii);
      }
      printf(" %02X", data[ii]&0xFF);
   }

   printf("\n");
   fflush(stdout);
}
void dump(const unsigned char *data, int numChar)
{
   dump((const char *)data, numChar);
}

void t(void)
{
   GOOGLE_PROTOBUF_VERIFY_VERSION;

   ris::RisBuffer b1;
   ris::KeyValue  kv;
   unsigned char array[128];
   unsigned char in[128];
   int      len;

   for ( int ii = 0; ii < 128; ii++ )
   {
      array[ii] = (unsigned char)ii;
   }

   b1.set_key(1);
   b1.set_data(array, 33);

   len = b1.data().length();
   memcpy(in, b1.data().data(), len);
   dump( in, len );
   printf("Data size %d\n", b1.data().length());

   printf("risBuffer DebugString:\n%s", b1.DebugString().data() );


   // Get started with ETCD key/value
   int ii=1;
   char tt[16];
   sprintf(tt, "Hello %02x", ii);
   kv.set_key("msg");
   kv.set_value(tt);
   kv.set_lease(0);
   len = kv.ByteSizeLong();
   kv.SerializeToArray(in, len);
   dump( in, len );
   printf("Data size %d ii %d %s\n", len, ii, kv.key().c_str() );

   printf("inside t\n");
}
