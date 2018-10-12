#include <stdio.h>
#include "t1.pb.h"
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

   t1::risBuffer b1;
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

   printf("inside t\n");
}
