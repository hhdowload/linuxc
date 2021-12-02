#ifndef SEMUN_H_
#define SEMUN_H_
union  semun{
int  val;
struct  semid_ds * buf;
unsigned  short  * array;
};
#endif /* SEMUN_H_ */
 