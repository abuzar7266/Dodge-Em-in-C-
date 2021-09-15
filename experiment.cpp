













static int count7=0;
if(up2==false && down2==false && rights2==false && lefts2==false && glit==0){		
	if((y2>70 && y2<800) && ((x2>80 && x2<750) || (x2<300)) && x3>370 && x3<460 && y2>y3 && y3<670 &&(y3<260 || y3>410)){
		up2=true;}}
	if(up2==true && down2==false && rights2==false && lefts2==false)
	{
		if(y3<310 && y3>40)
			{
				if(wait6==true){
				y3+=5;
				count7+=5;
				wait6=false;}
				if(count7==80)
				{
					up2=false;
					glit=50;
					jump8+=80;
					count7=0;
				}
			}
			if(y3<770 && y3>410)
			{
				if(wait6==true){
				y3+=5;
				count7+=5;
				wait6=false;}
				if(count7==80)
				{
					up2=false;
					glit=50;
					jump8-=80;
					count7=0;
				}
			}
	}
if(up2==false && down2==false && rights2==false && lefts2==false && glit==0){		
	if(y2>0 && y2<750-80 && ((x2>80 && x2<750) ||(x2>500)) && x3>360 && x3<450 && y2<y3 && y3<760 &&(y3<320 || y3>510)){
		down2=true;}}
	if(down2==true && up2==false && rights2==false && lefts2==false)
	{
		if(y3<350 && y3>55)
			{
				if(wait6==true)
				{
				y3-=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					down2=false;
					glit=50;
					jump8-=80;
					count7=0;
				}
			}
			if(y3<750 && y3>400)
			{
				if(wait6==true){
				y3-=5;
				count7+=5;
				wait6=false;}
				if(count7==80)
				{
					down2=false;
					glit=50;
					jump8+=80;
					count7=0;
				}
			}
	}
static int count7=0;
if(up2==false && glit==0 && down2==false && rights2==false && lefts2==false){		
	if(x2<x3 && (y3>330 && y3<410) && !(x3>340 && x3<500) && (x3<360 && x3>500)  && x3>50+jump8 && x3<760-jump8){
		lefts2=true;}}
	if(up2==false && down2==false && rights2==false && lefts2==true)
	{
		if(x3<350)
			{
				if(wait6==true)
				{
				x3-=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					lefts2=false;
					glit=50;
					jump8-=80;
					count7=0;
				}
			}	
		if(x3>450)
			{
				if(wait6==true)
				{
				x3-=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					lefts2=false;
					glit=50;
					jump8+=80;
					count7=0;
				}
			}
}
	if(up2==false && glit==0 && down2==false && rights2==false && lefts2==false){		
	if(x2>x3 && (y3>330 && y3<410) && !(x3>280 && x3<470) && ((x2>0 && x2<360) || (x2>400))  && x3>50+jump8 && x3<760-jump8){
		rights2=true;}}
	if(up2==false && down2==false && rights2==true && lefts2==false)
	{
		if(x3>0 && x3<350)
			{
				if(wait6==true)
				{
				x3+=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					rights2=false;
					glit=50;
					jump8+=80;
					count7=0;
				}
			}	
		if(x3>400 && x3<800)
			{
				if(wait6==true)
				{
				x3+=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					rights2=false;
					glit=50;
					jump8-=80;
					count7=0;
				}
			}	
	}	
	if(glit!=0){
	glit--;}
