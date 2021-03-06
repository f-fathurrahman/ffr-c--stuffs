#include <cstdlib>
#include <cstdio>

#include <ctime>
// atau include <time.h>

#include <string>
#include <cfloat>
#include <climits>

#include "sprig/sprig.h"
#include "wayang/wayang.h"

/* fungsi random float
 * kembali angka acak antara min - min+range, pecahan
 */
float randFloat(float min, float range) {
  return min + ((float) rand() / RAND_MAX * range);
}

// variabel global, agar bisa diakses oleh tugas5_2()
const int NWAYANG = 5;
hWayang matahari[NWAYANG];

void tugas5_1()
{
  
  matahari[0] = wCreate(1, "images/alam/matahari_01.png");

  for(int i = 1; i < NWAYANG; i++) {
    matahari[i] = wClone(matahari[0]);
  }
  
  const int XSTART = -350;
  const int DELTAX =  700/(NWAYANG-1);
  
  // inisialisasi bilangan random
  srand(clock());
  //
  for( int i = 0; i < NWAYANG; i++ ) {
    float scal = randFloat(0.8, 0.5);
    // skala
    wScale( matahari[i], scal );
    // hitung posisi x
    int xpos = XSTART + i*DELTAX;
    // posisi y selalu di 0
    wJumpTo( matahari[i], xpos, 0);
    wShow( matahari[i] );
	  printf("item = %d h = %d, w = %d\n", i, wGetH(matahari[i]), wGetW(matahari[i]));
  }
  
}

// sort
void tugas5_2()
{
  int i;
	int imins = 0;
  int imaks = 0;
  // komparasi dgn tinggi, pakai wGetH
  for( i = 0; i < NWAYANG; i++ ){
    if( wGetH(matahari[i]) < wGetH(matahari[imins]) ) imins = i;
    if( wGetH(matahari[i]) > wGetH(matahari[imaks]) ) imaks = i;
  }

  printf("max height = %d\n", wGetH(matahari[imaks]));
  printf("min height = %d\n", wGetH(matahari[imins]));

  wMove( matahari[imins], 0, -100) ;
  wMove( matahari[imaks], 0,  100) ;
  dDelay(1000);
}


int main()
{

  kOpen(800, 600, "images/wayang/keraton.jpg");

  tugas5_1();

  tugas5_2();

  dPause(5000);

  kClose();

  return 0;
}

