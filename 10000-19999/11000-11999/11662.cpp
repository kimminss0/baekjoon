/**
 * @author 김민서 <kimminss0@outlook.kr>
 * @date 2022-12-15
 */
#include <cstdio>
#include <cmath>
int main(void) {
  int ax,ay,bx,by,cx,cy,dx,dy,sx,sy;
  scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
  sx=bx-ax-dx+cx;
  sy=by-ay-dy+cy;
  double t=0;
  if (sx||sy) {
    t=((cx-ax)*sx+(cy-ay)*sy)/(double)(sx*sx+sy*sy);
    if (t>1) t=1;
    if (t<0) t=0;
  }
  printf("%.10f",sqrt(pow(ax-cx+t*sx,2)+pow(ay-cy+t*sy,2)));
}
