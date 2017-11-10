#include "MagixoomIPC.h"

int LUTK[101] ={0,	1,	3,	4,	5,	6,	8,	9,	10,\
							12,	13,	14,	15,	17,	18,	19,	20,	22,\
							23,	24,	26,	27,	28,	29,	31,	32,	33,\
							35,	36,	37,	38,	40,	41,	42,	44,	45,\
							46,	47,	49,	50,	51,	52,	54,	55,	56,\
							58,	59,	60,	61,	63,	64,	65,	67,	68,\
							69,	70,	72,	73,	74,	76,	77,	78,	79,\
							81,	82,	83,	84,	86,	87,	88,	90,	91,\
							92,	93,	95,	96,	97,	99,	100,101,102,\
							104,105,106,108,109,110,111,113,114,\
							115,116,118,119,120,122,123,124,125,\
							127,128};

MagixoomIPC::MagixoomIPC(void)
{

}


MagixoomIPC::~MagixoomIPC(void)
{

}

//算法载入数据
int MagixoomIPC::MagGMIPC_LoadData()
{
	FILE * TyLUTFile;

	WidthAssist = ASSISTWIDTH;
	HeightAssist = ASSISTHEIGHT;

	WidthMain = MAINWIDTH;
	HeightMain = MAINHEIGHT;

	OutWidth = OUTWIDTH;
	OutHeight = OUTHEIGHT;


	fopen_s(&TyLUTFile,"./MagData/HW.txt","rb");

	if (TyLUTFile == NULL)
	{
		return -1;
	}
	fread(&FullHeight,4,1,TyLUTFile);
	fread (&FullWidth,4,1,TyLUTFile);
	fclose(TyLUTFile);


	//
	TempLutDataAssist.k1 = (unsigned char *)malloc(OUTWIDTH*OUTHEIGHT);
	TempLutDataAssist.k2 = (unsigned char *)malloc(OUTWIDTH*OUTHEIGHT);
	TempLutDataAssist.k3 = (unsigned char *)malloc(OUTWIDTH*OUTHEIGHT);

	TempLutDataAssist.p1 = ( char *)malloc(OUTWIDTH*OUTHEIGHT);
	TempLutDataAssist.p2 = ( char *)malloc(OUTWIDTH*OUTHEIGHT);
	TempLutDataAssist.p3 = ( char *)malloc(OUTWIDTH*OUTHEIGHT);
	TempLutDataAssist.p4 = ( char *)malloc(OUTWIDTH*OUTHEIGHT);

	TempLutDataAssist.x1 = ( short *)malloc(OUTWIDTH*OUTHEIGHT*sizeof(short));
	TempLutDataAssist.y1 = ( short *)malloc(OUTWIDTH*OUTHEIGHT*sizeof(short));
	TempLutDataAssist.x2 = ( short *)malloc(OUTWIDTH*OUTHEIGHT*sizeof(short));
	TempLutDataAssist.y2 = ( short *)malloc(OUTWIDTH*OUTHEIGHT*sizeof(short));
	TempLutDataAssist.x3 = ( short *)malloc(OUTWIDTH*OUTHEIGHT*sizeof(short));
	TempLutDataAssist.y3 = ( short *)malloc(OUTWIDTH*OUTHEIGHT*sizeof(short));
	TempLutDataAssist.x4 = ( short *)malloc(OUTWIDTH*OUTHEIGHT*sizeof(short));
	TempLutDataAssist.y4 = ( short *)malloc(OUTWIDTH*OUTHEIGHT*sizeof(short));

	TempLutDataAssist.Yadjust = (unsigned char*)malloc(ASSISTWIDTH*ASSISTHEIGHT*sizeof(unsigned char));

	TempLutDataAssist.pNumOverlap = ( unsigned char * )malloc(OUTWIDTH*OUTHEIGHT);

	//读入全景LUT数据

	TyLUTFile = fopen("./MagData/pre_kk1.txt","rb");
	fread(TempLutDataAssist.k1,1,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_kk2.txt","rb");
	fread(TempLutDataAssist.k2,1,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_kk3.txt","rb");
	fread(TempLutDataAssist.k3,1,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_plane1.txt","rb");
	fread(TempLutDataAssist.p1,1,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_plane2.txt","rb");
	fread(TempLutDataAssist.p2,1,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_plane3.txt","rb");
	fread(TempLutDataAssist.p3,1,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_plane4.txt","rb");
	fread(TempLutDataAssist.p4,1,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_xx1.txt","rb");
	fread(TempLutDataAssist.x1,2,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_xx2.txt","rb");
	fread(TempLutDataAssist.x2,2,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_xx3.txt","rb");
	fread(TempLutDataAssist.x3,2,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_xx4.txt","rb");
	fread(TempLutDataAssist.x4,2,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_yy1.txt","rb");
	fread(TempLutDataAssist.y1,2,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_yy2.txt","rb");
	fread(TempLutDataAssist.y2,2,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_yy3.txt","rb");
	fread(TempLutDataAssist.y3,2,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_yy4.txt","rb");
	fread(TempLutDataAssist.y4,2,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/pre_n_overlap.txt","rb");
	fread(TempLutDataAssist.pNumOverlap,1,OUTWIDTH*OUTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/AdjustYAssist.txt","rb");
	fread(TempLutDataAssist.Yadjust,1,ASSISTWIDTH*ASSISTHEIGHT,TyLUTFile);
	fclose(TyLUTFile);


	//读入全细节LUT

	TempLutDataMain.k1 = (unsigned char *)malloc(FullWidth*FullHeight);
	TempLutDataMain.k2 = (unsigned char *)malloc(FullWidth*FullHeight);
	TempLutDataMain.k3 = (unsigned char *)malloc(FullWidth*FullHeight);

	TempLutDataMain.p1 = ( char *)malloc(FullWidth*FullHeight);
	TempLutDataMain.p2 = ( char *)malloc(FullWidth*FullHeight);
	TempLutDataMain.p3 = ( char *)malloc(FullWidth*FullHeight);
	TempLutDataMain.p4 = ( char *)malloc(FullWidth*FullHeight);

	TempLutDataMain.x1 = ( short *)malloc(FullWidth*FullHeight*sizeof(short));
	TempLutDataMain.y1 = ( short *)malloc(FullWidth*FullHeight*sizeof(short));
	TempLutDataMain.x2 = ( short *)malloc(FullWidth*FullHeight*sizeof(short));
	TempLutDataMain.y2 = ( short *)malloc(FullWidth*FullHeight*sizeof(short));
	TempLutDataMain.x3 = ( short *)malloc(FullWidth*FullHeight*sizeof(short));
	TempLutDataMain.y3 = ( short *)malloc(FullWidth*FullHeight*sizeof(short));
	TempLutDataMain.x4 = ( short *)malloc(FullWidth*FullHeight*sizeof(short));
	TempLutDataMain.y4 = ( short *)malloc(FullWidth*FullHeight*sizeof(short));

	TempLutDataMain.Yadjust = (unsigned char*)malloc(MAINWIDTH*MAINHEIGHT*sizeof(unsigned char));

	TempLutDataMain.pNumOverlap = ( unsigned char * )malloc(FullWidth*FullHeight);

	//读入全景LUT数据

	TyLUTFile = fopen("./MagData/kk1.txt","rb");
	fread(TempLutDataMain.k1,1,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/kk2.txt","rb");
	fread(TempLutDataMain.k2,1,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/kk3.txt","rb");
	fread(TempLutDataMain.k3,1,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/plane1.txt","rb");
	fread(TempLutDataMain.p1,1,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/plane2.txt","rb");
	fread(TempLutDataMain.p2,1,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/plane3.txt","rb");
	fread(TempLutDataMain.p3,1,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/plane4.txt","rb");
	fread(TempLutDataMain.p4,1,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/xx1.txt","rb");
	fread(TempLutDataMain.x1,2,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/xx2.txt","rb");
	fread(TempLutDataMain.x2,2,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/xx3.txt","rb");
	fread(TempLutDataMain.x3,2,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/xx4.txt","rb");
	fread(TempLutDataMain.x4,2,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/yy1.txt","rb");
	fread(TempLutDataMain.y1,2,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/yy2.txt","rb");
	fread(TempLutDataMain.y2,2,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/yy3.txt","rb");
	fread(TempLutDataMain.y3,2,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/yy4.txt","rb");
	fread(TempLutDataMain.y4,2,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/n_overlap.txt","rb");
	fread(TempLutDataMain.pNumOverlap,1,FullWidth*FullHeight,TyLUTFile);
	fclose(TyLUTFile);

	TyLUTFile = fopen("./MagData/AdjustY.txt","rb");
	fread(TempLutDataMain.Yadjust,1,MAINWIDTH*MAINHEIGHT,TyLUTFile);
	fclose(TyLUTFile);

	return 0;
}
//算法释放数据
int MagixoomIPC::MagGMIPC_RealseData()
{
	free(TempLutDataAssist.pNumOverlap);
	free(TempLutDataAssist.k1);
	free(TempLutDataAssist.k2);
	free(TempLutDataAssist.k3);
	free(TempLutDataAssist.p1);
	free(TempLutDataAssist.p2);
	free(TempLutDataAssist.p3);
	free(TempLutDataAssist.p4);
	free(TempLutDataAssist.x1);
	free(TempLutDataAssist.x2);
	free(TempLutDataAssist.x3);
	free(TempLutDataAssist.x4);
	free(TempLutDataAssist.y1);
	free(TempLutDataAssist.y2);
	free(TempLutDataAssist.y3);
	free(TempLutDataAssist.y4);

	free(TempLutDataMain.pNumOverlap);
	free(TempLutDataMain.k1);
	free(TempLutDataMain.k2);
	free(TempLutDataMain.k3);
	free(TempLutDataMain.p1);
	free(TempLutDataMain.p2);
	free(TempLutDataMain.p3);
	free(TempLutDataMain.p4);
	free(TempLutDataMain.x1);
	free(TempLutDataMain.x2);
	free(TempLutDataMain.x3);
	free(TempLutDataMain.x4);
	free(TempLutDataMain.y1);
	free(TempLutDataMain.y2);
	free(TempLutDataMain.y3);
	free(TempLutDataMain.y4);



	return 0;
}

//全景流成图库
int MagixoomIPC::MagGMIPC_StitchAssist(unsigned char *image_in[MAXCAMNUM],unsigned char *image_out)
{
	unsigned char *pNumOverlap;//

	short  *LUTx1;
	short  *LUTy1;
	short  *LUTx2;
	short  *LUTy2;
	short  *LUTx3;
	short  *LUTy3;
	short  *LUTx4;
	short  *LUTy4;

	char *LUTp1;
	char *LUTp2;
	char *LUTp3;
	char *LUTp4;

	unsigned char* YadjustData;

	unsigned char *LUTk1;//0-1
	unsigned char *LUTk2;
	unsigned char *LUTk3;

	//int m,n,k;
	int i,j;
	int ii,jj;
	char p1,p2,p3,p4;
	char nNumOverlap;
	short x1,y1,x2,y2,x3,y3,x4,y4;
	int kk1,kk2,kk3;
	int k1,k2,k3;

	char tempp1;
	short tempx1;
	short tempy1;

	int tempyuv1;
	int tempyuv2;

	int tempalia = 0;
	int tempaliadst = 0;
	int addralia1 = 0;
	int addralia2 = 0;
	int addralia3 = 0;
	int addralia4 = 0;

	int tempLutWidth = OutWidth;
	int tempwidthStep = OutWidth ;
	int tempinitwidthStep = WidthAssist ;

	int pre_WH_U = OutWidth*OutHeight;
	int pre_WH_V = OutWidth*OutHeight*5/4;

	int pre_wh_U = WidthAssist*HeightAssist;
	int pre_wh_V = WidthAssist*HeightAssist*5/4; 

	int tempWidth_half = OutWidth/2;
	int initWidth_half = WidthAssist/2;

	int tempyy1,tempyy2,tempyy3,tempyy4;
	int tempu1,tempu2,tempu3,tempu4;
	int tempv1,tempv2,tempv3,tempv4;

	int Yadjust1,Yadjust2,Yadjust3,Yadjust4;

	pNumOverlap = TempLutDataAssist.pNumOverlap;
	LUTp1 = TempLutDataAssist.p1;
	LUTp2 = TempLutDataAssist.p2;
	LUTp3 = TempLutDataAssist.p3;
	LUTp4 = TempLutDataAssist.p4;
	LUTk1 = TempLutDataAssist.k1;
	LUTk2 = TempLutDataAssist.k2;
	LUTk3 = TempLutDataAssist.k3;
	LUTx1 = TempLutDataAssist.x1;
	LUTx2 = TempLutDataAssist.x2;
	LUTx3 = TempLutDataAssist.x3;
	LUTx4 = TempLutDataAssist.x4;
	LUTy1 = TempLutDataAssist.y1;
	LUTy2 = TempLutDataAssist.y2;
	LUTy3 = TempLutDataAssist.y3;
	LUTy4 = TempLutDataAssist.y4;
	YadjustData = TempLutDataAssist.Yadjust;
	//*****************************************************
		//缝合线声明
	short startx1,starty1,startx2,starty2,endx1,endx2,endy1,endy2;
	int first=0;
	FILE * f;
	f = fopen("caijian_lut.txt","wb");
	//*****************************************************
	for ( i = 0; i < OutHeight; i++ )
	{
		for ( j = 0; j < OutWidth; j++ )
		{
			tempalia = i * tempLutWidth + j;
			tempaliadst = i*tempwidthStep + j;
			nNumOverlap = *(pNumOverlap + tempalia);
			switch(nNumOverlap)
				//四种重叠情况
			{
			case 1:

				p1 = *(LUTp1 + tempalia);//用OutWidth是因为OutWidth!=tempWidth
				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*ASSISTWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				*(image_out + tempaliadst) = tempyy1;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
				}

				break;

			case 2:
			
				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);

				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);
				x2 = *(LUTx2 + tempalia);
				y2 = *(LUTy2 + tempalia);

				kk1 = *(LUTk1 + tempalia);

				k1 = LUTK[kk1];

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*ASSISTWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*ASSISTWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);
			
				*(image_out + tempaliadst ) = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempv1*k1 + tempv2*(128-k1))>>7;
				}

				

				//上面是二重叠情况*********************************************

				//记录重叠区域的坐标
				if (p1==0&&p2==1){
					if (first==0)
					{
						startx1=x1;
						startx2=x2;
						starty1=y1;
						starty2=y2;
						first=1;
					}
					endy2=y2;
					
					}
				
				fwrite((LUTx1 + tempalia),1,1,f);
				fwrite((LUTy1 + tempalia),1,1,f);

				//*********************************************************8
				break;
			case 3:

				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);
				p3 = *(LUTp3 + tempalia);
				p4 = *(LUTp4 + tempalia);

				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);
				x2 = *(LUTx2 + tempalia);
				y2 = *(LUTy2 + tempalia);
				x3 = *(LUTx3 + tempalia);
				y3 = *(LUTy3 + tempalia);
				x4 = *(LUTx4 + tempalia);
				y4 = *(LUTy4 + tempalia);

				kk1 = *(LUTk1 + tempalia);
				kk2 = *(LUTk2 + tempalia);
				kk3 = *(LUTk3 + tempalia);  

				k1 = LUTK[kk1];
				k2 = LUTK[kk2];
				k3 = LUTK[kk3];

				if (p3==-1)
				{
					p3 = p4;
					x3 = x4;
					y3 = y4;
				}
				else if (p2==-1)
				{
					tempp1 = p1;
					tempx1 = x1;
					tempy1 = y1;

					p1 = p3;
					x1 = x3;
					y1 = y3;

					p2 = p4;
					x2 = x4;
					y2 = y4;

					p3 = tempp1;
					x3 = tempx1;
					y3 = tempy1;

					k1 = k2;
					k3 = 128 - k3;				
				}

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*ASSISTWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*ASSISTWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);

				tempyuv1 = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				tempyuv2 = *(image_in[p3] + y3*tempinitwidthStep + x3 );
				Yadjust3 = *(YadjustData+y3*ASSISTWIDTH+x3);
				tempyuv2 = MIN(255,tempyuv2*Yadjust3>>7);

				*(image_out + tempaliadst ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;
				
				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempyuv2 = *(image_in[p3] + pre_wh_U + (y3/2)*initWidth_half + x3/2 );

					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;

					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempv1*k1 + tempv2*(128-k1))>>7;
					tempyuv2 = *(image_in[p3] + pre_wh_V + (y3/2)*initWidth_half + x3/2 );

					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;
				}


				break;
			case 4:

				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);
				p3 = *(LUTp3 + tempalia);
				p4 = *(LUTp4 + tempalia);

				x1 = *(LUTx1 + tempalia) ;
				y1 = *(LUTy1 + tempalia) ;
				x2 = *(LUTx2 + tempalia) ;
				y2 = *(LUTy2 + tempalia) ;
				x3 = *(LUTx3 + tempalia) ;
				y3 = *(LUTy3 + tempalia) ;
				x4 = *(LUTx4 + tempalia) ;
				y4 = *(LUTy4 + tempalia) ;

				kk1 = *(LUTk1 + tempalia);
				kk2 = *(LUTk2 + tempalia);  
				kk3 = *(LUTk3 + tempalia);  

				k1 = LUTK[kk1];
				k2 = LUTK[kk2];
				k3 = LUTK[kk3];

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*ASSISTWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*ASSISTWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);

				tempyuv1 = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				tempyy3 = *(image_in[p3] + y3*tempinitwidthStep + x3 );
				Yadjust3 = *(YadjustData+y3*ASSISTWIDTH+x3);
				tempyy3 = MIN(255,tempyy3*Yadjust3>>7);
				tempyy4 = *(image_in[p4] + y4*tempinitwidthStep + x4 );
				Yadjust4 = *(YadjustData+y4*ASSISTWIDTH+x4);
				tempyy4 = MIN(255,tempyy4*Yadjust4>>7);



				tempyuv2 = (tempyy3*k2 + tempyy4*(128-k2))>>7;
				*(image_out + tempaliadst ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7 ;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;

					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempu3 = *(image_in[p3] + pre_wh_U + (y3/2)*initWidth_half + x3/2 );
					tempu4 = *(image_in[p4] + pre_wh_U + (y4/2)*initWidth_half + x4/2 );
					tempyuv2 = (tempu3*k1 + tempu4*(128-k1))>>7;
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;

					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempv1*k1 + tempv2*(128-k1))>>7;
					tempv3 = *(image_in[p3] + pre_wh_V + (y3/2)*initWidth_half + x3/2 );
					tempv4 = *(image_in[p4] + pre_wh_V + (y4/2)*initWidth_half + x4/2 );
					tempyuv2 = (tempv3*k1 + tempv4*(128-k1))>>7;
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;
				}

				break;
			}
		}
	}
	fclose(f);	
	//##############################################
	//计算缝合线,先不考虑灰度调节
	//#define ASSISTWIDTH 704
 //   #define ASSISTHEIGHT 576
	//int H=ASSISTHEIGHT ;
	//int W= ASSISTWIDTH;

	//float tempE,minE;
	//float R,G,B;
	//vector<vector<float>> imgr_l(H,vector<float>(W)); 
	//vector<vector<float>> imgg_l(H,vector<float>(W)); 
	//vector<vector<float>> imgb_l(H,vector<float>(W)); 
	//vector<vector<float>> imgr_r(H,vector<float>(W)); 
	//vector<vector<float>> imgg_r(H,vector<float>(W)); 
	//vector<vector<float>> imgb_r(H,vector<float>(W)); 
	//vector<vector<float>> img_l(H,vector<float>(W)); 
	//vector<vector<float>> img_r(H,vector<float>(W)); 


	//for (int i=0; i < H; i++) 
	//	for (int j=0;j<W;j++){

	//		imgr_l[i][j] = R = *(image_in[p1] + i*tempinitwidthStep + j );
	//		imgg_l[i][j] = G = *(image_in[p1] + pre_wh_U + (i/2)*initWidth_half + j/2);
	//		imgb_l[i][j] = B = *(image_in[p1] + pre_wh_V + (i/2)*initWidth_half + j/2);
	//		
	//		//Gray = (R*299 + G*587 + B*114 + 500) / 1000
	//		img_l[i][j]= (R*299 + G*587 + B*114 + 500) / 1000;

	//		imgr_r[i][j] = R = *(image_in[p2] + i*tempinitwidthStep + j );
	//		imgg_r[i][j] = G = *(image_in[p2] + pre_wh_U + (i/2)*initWidth_half + j/2);
	//		imgb_r[i][j] = B = *(image_in[p2] + pre_wh_V + (i/2)*initWidth_half + j/2);

	//		//Gray = (R*299 + G*587 + B*114 + 500) / 1000
	//		img_r[i][j]= (R*299 + G*587 + B*114 + 500) / 1000;

	//	} 
	//FILE * f;
	/*f = fopen("caijian_lut.yuv","wb");
	fwrite(img_l,1,OUTPUT_IMAGE_WIDTH*OUTPUT_IMAGE_HEIGHT*3/2,f);
	fclose(f);*/
	//	float Ecolor;
	//	float Egeometry;
	//	int a1,b1,c1,a2,b2,c2,y,color1,color2;
	//	int overflapW=endx2-startx1+1;//重叠区域宽度
	//	int overflapH=endy2-starty1+1;
	//	float* Etotal=new float[overflapW];
	//	int **path=new int*[overflapH];
	//	for (int i=0;i<overflapH;i++){
	//		path[i]=new int[overflapW];

	//	}

	//	for (int i=0;i<overflapW;i++){
	//		Etotal[i]=0;

	//	}

	//	//色差=两种颜色对应通道色阶差的正最大值-两种颜色对应通道色阶差的负最小值，
	//	//如果没有正值或负值，则正最大值或负最大值以0计。实际上也就是某种颜色偏离取样色的最大范围（包括正向和负向）。
	//	//第一行初始化 
	//	first=0;;//用来判断是否是第一次赋值
	//	int xx1,yy1,xx2,yy2;
	//	for(int xx=0;xx<1;xx++)
	//	{
	//		for (int yy=0;yy<overflapW;yy++)
	//		{
	//			xx1=starty1+xx;yy1=startx1+yy;
	//			xx2=starty2+xx;yy2=startx2+yy;
	//			a1=imgr_l[xx1][yy1];b1=imgg_l[xx1][yy1];c1=imgb_l[xx1][yy1];
	//			a2=imgr_r[xx2][yy2];b2=imgg_r[xx2][yy2];c2=imgb_r[xx2][yy2];
	//			color1=max(max(a1-a2,b1-b2),c1-c2)<0? 0:max(max(a1-a2,b1-b2),c1-c2);
	//			color2=min(min(a1-a2,b1-b2),c1-c2)>0? 0:min(min(a1-a2,b1-b2),c1-c2);
	//			Ecolor=(color1-color2)*(color1-color2);
	//			if(yy==0)
	//			{
	//				Egeometry=((img_l[xx1][yy1+1]+2*img_l[xx1+1][yy1+1])-(img_r[xx2][yy2+1]+2*img_r[xx2][yy2+1]))*
	//					(-(img_l[xx1+1][yy1]+2*img_l[xx1+1][yy1+1])+(img_r[xx2+1][yy2]+2*img_r[xx2+1][yy2+1]));
	//			}
	//			else if(j==overflapW-1){
	//				Egeometry=(-(img_l[xx1][yy1-1]+2*img_l[xx1+1][yy1-1])+(img_r[xx2][yy2-1]+2*img_r[xx2+1][yy2-1]))*
	//					(-(img_l[xx1+1][yy1]+2*img_l[xx1+1][yy1-1])+(img_r[xx2+1][yy2]+2*img_r[xx1+1][j-1]));
	//			}
	//			else{
	//				Egeometry=((img_l[xx1][yy1+1]+2*img_l[xx1+1][yy1+1])-(img_l[xx1][yy1-1]+2*img_l[1][yy1-1])-(img_r[xx2][yy2+1]+2*img_r[xx2+1][yy2+1]-img_r[xx2][yy2-1]-2*img_r[xx2+1][yy2-1]))*
	//					(-(img_l[xx1+1][yy1]+2*img_l[xx1+1][yy1-1]+2*img_l[xx1+1][yy1+1])+(img_r[xx2+1][yy2]+2*img_r[xx2+1][yy2-1]+2*img_r[xx2+1][yy2+1]));
	//			}
	//			Etotal[yy]=Ecolor+abs(Egeometry);
	//			path[0][yy]=yy;
	//		}
	//	}
	//	for(int k=0;k<overflapW;k++)
	//		//第k条路径
	//	{
	//		for (int i=1;i<overflapH;i++)

	//		{
	//			first=0;
	//			for (int j=path[i-1][k]-1;j<path[i-1][k]+2;j++)
	//			{

	//				if(j<0||j>overflapW-1)
	//					continue;
	//				xx1=starty1+i;
	//				y=startx1+j;
	//				xx2=starty2+i;
	//				yy2=startx2+j;
	//				a1=imgr_l[xx1][y];b1=imgg_l[xx1][y];c1=imgb_l[xx1][y];
	//				a2=imgr_r[xx2][yy2];b2=imgg_r[xx2][yy2];c2=imgb_r[xx2][yy2];
	//				color1=max(max(a1-a2,b1-b2),c1-c2)<0? 0:max(max(a1-a2,b1-b2),c1-c2);
	//				color2=min(min(a1-a2,b1-b2),c1-c2)>0? 0:min(min(a1-a2,b1-b2),c1-c2);
	//				Ecolor=(color1-color2)*(color1-color2);
	//				if(j==0&&i<=overflapH-2){
	//					Egeometry=((2*img_l[xx1-1][y+1]+img_l[xx1][y+1]+2*img_l[xx1+1][y+1])-(2*img_r[xx2-1][yy2+1]+img_r[xx2][yy2+1]+2*img_r[xx2+1][yy2+1]))*
	//						((img_l[xx1-1][y]+2*img_l[xx1-1][y+1]-img_l[xx1+1][y]-2*img_l[xx1+1][y+1])-(img_r[xx2-1][yy2]+2*img_r[xx2-1][yy2+1]-img_r[xx2+1][yy2]-2*img_r[xx2+1][yy2+1]));
	//				}
	//				else  if(j==-1&&i<=overflapH-2){
	//					Egeometry=(-(2*img_l[xx1-1][y-1]+img_l[xx1][y-1]+2*img_l[xx1+1][y-1])+(2*img_r[xx2-1][yy2-1]+img_r[xx2][yy2-1]+2*img_r[xx2+1][yy2-1]))*
	//						((2*img_l[xx1-1][y-1]+img_l[xx1-1][y]-2*img_l[xx1+1][y-1]-img_l[xx1+1][y])-(2*img_r[xx2-1][yy2-1]+img_r[xx2-1][yy2]-2*img_r[xx2+1][yy2-1]-img_r[xx2+1][yy2]));
	//				}
	//				else if(i<=overflapH-2){
	//					Egeometry=(2*img_l[xx1-1][y+1]+img_l[xx1][y+1]+2*img_l[xx1+1][y+1]-2*img_l[xx1-1][y-1]-img_l[xx1][y-1]-2*img_l[xx1+1][y-1]-
	//						(2*img_r[xx2-1][yy2+1]+img_r[xx2][yy2+1]+2*img_r[xx2+1][yy2+1]-2*img_r[xx2-1][yy2-1]-img_r[xx2][yy2-1]-2*img_r[xx2+1][yy2-1]))*
	//						(2*img_l[xx1-1][y-1]+img_l[xx1-1][y]+2*img_l[xx1-1][y+1]-2*img_l[xx1+1][y-1]-img_l[xx1+1][y]-2*img_l[xx1+1][y+1]-
	//						(2*img_r[xx2-1][yy2-1]+img_r[xx2-1][yy2]+2*img_r[xx2-1][yy2+1]-2*img_r[xx2+1][yy2-1]-img_r[xx2+1][yy2]-2*img_r[xx2+1][yy2+1]));
	//				}
	//				else if(j==0){
	//					Egeometry=(2*img_l[xx1-1][y+1]+img_l[xx1][y+1]-(2*img_r[xx2-1][yy2+1]+img_r[xx2][yy2+1]))*
	//						(img_l[xx1-1][y]+2*img_l[xx1-1][y+1]-(img_r[xx2-1][yy2]+2*img_r[xx2-1][yy2+1]));
	//				}
	//				else if(j==overflapW-1){
	//					Egeometry=(-2*img_l[xx1-1][y-1]-img_l[xx1][y-1]+2*img_r[xx2-1][y-1]+img_r[xx2][y-1])*
	//						(2*img_l[xx1-1][y-1]+img_l[xx1-1][y]-2*img_r[xx2-1][yy2-1]-img_r[xx2-1][yy2]);
	//				}
	//				else{
	//					Egeometry=(2*img_l[xx1-1][y+1]+img_l[xx1][y+1]-2*img_l[xx1-1][y-1]-img_l[xx1][y-1]-(2*img_r[xx2-1][yy2+1]+img_r[xx2][yy2+1]-2*img_r[xx2-1][yy2-1]-img_r[xx2][yy2-1]))*
	//						(img_l[xx1-1][y-1]*2+img_l[xx1-1][y]+img_l[xx1-1][y+1]*2-2*img_r[xx2-1][yy2-1]-img_r[xx2-1][yy2]-2*img_r[xx2-1][yy2+1]);
	//				}
	//				tempE=Ecolor+Egeometry;
	//				if (first==0)
	//					minE=tempE;
	//				if(tempE<=minE){
	//					minE=tempE;
	//					path[i][k]=j;
	//					first=1;
	//				}

	//			}
	//			Etotal[k]=Etotal[k]+minE;
	//			
	//		}


	//	}
	//	minE=Etotal[0];
	//	int num=0;
	//	for(int k=1;k<overflapW;k++)
	//	{
	//		
	//		tempE=Etotal[k];
	//		if(tempE<minE)
	//		{
	//			minE=tempE;
	//			num=k;
	//		}

	//	}

	//


	//##############################################
	return 0;
}
//局部流成图库
int MagixoomIPC::MagGMIPC_StitchAOI(unsigned char *image_in[MAXCAMNUM],TyPoint tPoint,unsigned char *image_out)
{

	int StartX,StartY;
	unsigned char *pNumOverlap;

	short  *LUTx1;
	short  *LUTy1;
	short  *LUTx2;
	short  *LUTy2;
	short  *LUTx3;
	short  *LUTy3;
	short  *LUTx4;
	short  *LUTy4;

	char *LUTp1;
	char *LUTp2;
	char *LUTp3;
	char *LUTp4;

	unsigned char *LUTk1;
	unsigned char *LUTk2;
	unsigned char *LUTk3;

	unsigned char* YadjustData;

	//int m,n,k;
	int i,j;
	int ii,jj;
	char p1,p2,p3,p4;
	char nNumOverlap;
	short x1,y1,x2,y2,x3,y3,x4,y4;
	int kk1,kk2,kk3;
	int k1,k2,k3;

	char tempp1;
	short tempx1;
	short tempy1;

	int tempyuv1;
	int tempyuv2;
	int tempalia = 0;
	int tempaliadst = 0;
	int addralia1 = 0;
	int addralia2 = 0;
	int addralia3 = 0;
	int addralia4 = 0;

	int tempLutWidth = FullWidth;
	int tempwidthStep = OutWidth ;
	int tempinitwidthStep = WidthMain ;

	int pre_WH_U = OutWidth*OutHeight;
	int pre_WH_V = OutWidth*OutHeight*5/4;

	int pre_wh_U = WidthMain*HeightMain;
	int pre_wh_V = WidthMain*HeightMain*5/4; 

	int tempWidth_half = OutWidth/2;
	int initWidth_half = WidthMain/2;

	int tempyy1,tempyy2,tempyy3,tempyy4;
	int tempu1,tempu2,tempu3,tempu4;
	int tempv1,tempv2,tempv3,tempv4;

	int Yadjust1,Yadjust2,Yadjust3,Yadjust4;

	pNumOverlap = TempLutDataMain.pNumOverlap;
	LUTp1 = TempLutDataMain.p1;
	LUTp2 = TempLutDataMain.p2;
	LUTp3 = TempLutDataMain.p3;
	LUTp4 = TempLutDataMain.p4;
	LUTk1 = TempLutDataMain.k1;
	LUTk2 = TempLutDataMain.k2;
	LUTk3 = TempLutDataMain.k3;
	LUTx1 = TempLutDataMain.x1;
	LUTx2 = TempLutDataMain.x2;
	LUTx3 = TempLutDataMain.x3;
	LUTx4 = TempLutDataMain.x4;
	LUTy1 = TempLutDataMain.y1;
	LUTy2 = TempLutDataMain.y2;
	LUTy3 = TempLutDataMain.y3;
	LUTy4 = TempLutDataMain.y4;
	YadjustData = TempLutDataMain.Yadjust;

	StartX = tPoint.x - OutWidth/2;
	StartY = tPoint.y - OutHeight/2;

	if (tPoint.x - OutWidth/2 < 0)
	{
		StartX = 0;
	}

	if (tPoint.x - OutWidth/2 > FullWidth-OutWidth)
	{
		StartX = MAX(0,FullWidth - OutWidth);
	}

	if (tPoint.y - OutHeight/2 < 0)
	{
		StartY = 0;
	}

	if (tPoint.y- OutHeight/2 > FullHeight-OutHeight)
	{
		StartY = MAX(0,FullHeight-OutHeight);
	}

	for ( i = 0 ;i < MIN(FullHeight,OutHeight); i++ )
	{
		for ( j = 0; j < MIN(FullWidth,OutWidth); j++ )
		{
			tempalia = (i+StartY) * tempLutWidth + (j+StartX);
			tempaliadst = i*tempwidthStep + j;
			nNumOverlap = *(pNumOverlap + tempalia);
			switch(nNumOverlap)
			{
			case 1:

				p1 = *(LUTp1 + tempalia);//用OutWidth是因为OutWidth!=tempWidth
				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*MAINWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				*(image_out + tempaliadst) = tempyy1;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
				}

				break;

			case 2:

				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);

				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);
				x2 = *(LUTx2 + tempalia);
				y2 = *(LUTy2 + tempalia);

				kk1 = *(LUTk1 + tempalia);

				k1 = LUTK[kk1];

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*MAINWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*MAINWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);

				*(image_out + tempaliadst ) = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempv1*k1 + tempv2*(128-k1))>>7;
				}


				break;

			case 3:
				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);
				p3 = *(LUTp3 + tempalia);
				p4 = *(LUTp4 + tempalia);

				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);
				x2 = *(LUTx2 + tempalia);
				y2 = *(LUTy2 + tempalia);
				x3 = *(LUTx3 + tempalia);
				y3 = *(LUTy3 + tempalia);
				x4 = *(LUTx4 + tempalia);
				y4 = *(LUTy4 + tempalia);

				kk1 = *(LUTk1 + tempalia);
				kk2 = *(LUTk2 + tempalia);
				kk3 = *(LUTk3 + tempalia);  

				k1 = LUTK[kk1];
				k2 = LUTK[kk2];
				k3 = LUTK[kk3];

				if (p3==-1)
				{
					p3 = p4;
					x3 = x4;
					y3 = y4;
				}
				else if (p2==-1)
				{
					tempp1 = p1;
					tempx1 = x1;
					tempy1 = y1;

					p1 = p3;
					x1 = x3;
					y1 = y3;

					p2 = p4;
					x2 = x4;
					y2 = y4;

					p3 = tempp1;
					x3 = tempx1;
					y3 = tempy1;

					k1 = k2;
					k3 = 128 - k3;				
				}

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*MAINWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*MAINWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);

				tempyuv1 = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				tempyuv2 = *(image_in[p3] + y3*tempinitwidthStep + x3 );
				Yadjust3 = *(YadjustData+y3*MAINWIDTH+x3);
				tempyuv2 = MIN(255,tempyuv2*Yadjust3>>7);

				*(image_out + tempaliadst ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempyuv2 = *(image_in[p3] + pre_wh_U + (y3/2)*initWidth_half + x3/2 );

					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;

					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempv1*k1 + tempv2*(128-k1))>>7;
					tempyuv2 = *(image_in[p3] + pre_wh_V + (y3/2)*initWidth_half + x3/2 );

					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;
				}

				break;
			case 4:

				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);
				p3 = *(LUTp3 + tempalia);
				p4 = *(LUTp4 + tempalia);

				x1 = *(LUTx1 + tempalia) ;
				y1 = *(LUTy1 + tempalia) ;
				x2 = *(LUTx2 + tempalia) ;
				y2 = *(LUTy2 + tempalia) ;
				x3 = *(LUTx3 + tempalia) ;
				y3 = *(LUTy3 + tempalia) ;
				x4 = *(LUTx4 + tempalia) ;
				y4 = *(LUTy4 + tempalia) ;

				kk1 = *(LUTk1 + tempalia);
				kk2 = *(LUTk2 + tempalia);  
				kk3 = *(LUTk3 + tempalia);  

				k1 = LUTK[kk1];
				k2 = LUTK[kk2];
				k3 = LUTK[kk3];

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*MAINWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*MAINWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);

				tempyuv1 = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				tempyy3 = *(image_in[p3] + y3*tempinitwidthStep + x3 );
				Yadjust3 = *(YadjustData+y3*MAINWIDTH+x3);
				tempyy3 = MIN(255,tempyy3*Yadjust3>>7);
				tempyy4 = *(image_in[p4] + y4*tempinitwidthStep + x4 );
				Yadjust4 = *(YadjustData+y4*MAINWIDTH+x4);
				tempyy4 = MIN(255,tempyy4*Yadjust4>>7);



				tempyuv2 = (tempyy3*k2 + tempyy4*(128-k2))>>7;
				*(image_out + tempaliadst ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7 ;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;

					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempu3 = *(image_in[p3] + pre_wh_U + (y3/2)*initWidth_half + x3/2 );
					tempu4 = *(image_in[p4] + pre_wh_U + (y4/2)*initWidth_half + x4/2 );
					tempyuv2 = (tempu3*k1 + tempu4*(128-k1))>>7;
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;

					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempv1*k1 + tempv2*(128-k1))>>7;
					tempv3 = *(image_in[p3] + pre_wh_V + (y3/2)*initWidth_half + x3/2 );
					tempv4 = *(image_in[p4] + pre_wh_V + (y4/2)*initWidth_half + x4/2 );
					tempyuv2 = (tempv3*k1 + tempv4*(128-k1))>>7;
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;
				}



				break;
			}
		}
	}



	return 0;
}
int MagixoomIPC::MagGMIPC_StitchAOI_BirdView(unsigned char *image_in[MAXCAMNUM],TyPoint tPoint,int currbirdviewWidth,int currbirdviewHeight,unsigned char *image_out)
{
	//鸟瞰成图代码

	int StartX,StartY;
	unsigned char *pNumOverlap;

	short  *LUTx1;
	short  *LUTy1;
	short  *LUTx2;
	short  *LUTy2;
	short  *LUTx3;
	short  *LUTy3;
	short  *LUTx4;
	short  *LUTy4;

	char *LUTp1;
	char *LUTp2;
	char *LUTp3;
	char *LUTp4;

	unsigned char *LUTk1;
	unsigned char *LUTk2;
	unsigned char *LUTk3;

	unsigned char* YadjustData;

	//int m,n,k;
	int i,j;
	int ii,jj;
	char p1,p2,p3,p4;
	char nNumOverlap;
	short x1,y1,x2,y2,x3,y3,x4,y4;
	int kk1,kk2,kk3;
	int k1,k2,k3;

	char tempp1;
	short tempx1;
	short tempy1;

	int tempyuv1;
	int tempyuv2;
	int tempalia = 0;
	int tempaliadst = 0;
	int addralia1 = 0;
	int addralia2 = 0;
	int addralia3 = 0;
	int addralia4 = 0;

	int tempLutWidth = FullWidth;
	int tempwidthStep = OutWidth ;
	int tempinitwidthStep = WidthMain ;

	int pre_WH_U = OutWidth*OutHeight;
	int pre_WH_V = OutWidth*OutHeight*5/4;

	int pre_wh_U = WidthMain*HeightMain;
	int pre_wh_V = WidthMain*HeightMain*5/4; 

	int tempWidth_half = OutWidth/2;
	int initWidth_half = WidthMain/2;

	int tempyy1,tempyy2,tempyy3,tempyy4;
	int tempu1,tempu2,tempu3,tempu4;
	int tempv1,tempv2,tempv3,tempv4;

	int Yadjust1,Yadjust2,Yadjust3,Yadjust4;

	pNumOverlap = TempLutDataMain.pNumOverlap;
	LUTp1 = TempLutDataMain.p1;
	LUTp2 = TempLutDataMain.p2;
	LUTp3 = TempLutDataMain.p3;
	LUTp4 = TempLutDataMain.p4;
	LUTk1 = TempLutDataMain.k1;
	LUTk2 = TempLutDataMain.k2;
	LUTk3 = TempLutDataMain.k3;
	LUTx1 = TempLutDataMain.x1;
	LUTx2 = TempLutDataMain.x2;
	LUTx3 = TempLutDataMain.x3;
	LUTx4 = TempLutDataMain.x4;
	LUTy1 = TempLutDataMain.y1;
	LUTy2 = TempLutDataMain.y2;
	LUTy3 = TempLutDataMain.y3;
	LUTy4 = TempLutDataMain.y4;
	YadjustData = TempLutDataMain.Yadjust;

	int new_width,new_height;
	int newi,newj;
	int orix,oriy;
	float zoom_para = 0.0;
	float xleft,xright,yupper,ydown;

	zoom_para = (float)currbirdviewWidth / (float)OutWidth;

	if (FullWidth*9 > FullHeight*16)
	{
		xleft = 0;
		xright = FullWidth;
		yupper = (BirdVIewHeight - FullHeight)/2;
		ydown = (BirdVIewHeight + FullHeight)/2;

	}
	else
	{
		xleft = (BirdVIewWidth-FullWidth)/2;
		xright = (BirdVIewWidth+FullWidth)/2;
		yupper = 0;
		ydown = FullHeight;
	}

	StartX = tPoint.x;
	StartY = tPoint.y;

	for ( i = 0 ;i < MIN(FullHeight,OutHeight); i++ )
	{
		for ( j = 0; j < MIN(FullWidth,OutWidth); j++ )
		{
			newi = i * zoom_para;
			newj = j * zoom_para;

			orix = StartX + newj;
			oriy = StartY + newi;

			if (orix < xleft || orix >= xright || oriy < yupper || oriy >= ydown)
			{
				continue;
			}

			orix -= xleft;
			oriy -= yupper;

			tempalia = oriy * tempLutWidth + orix;
			tempaliadst = i*tempwidthStep + j;
			nNumOverlap = *(pNumOverlap + tempalia);
			switch(nNumOverlap)
			{
			case 1:

				p1 = *(LUTp1 + tempalia);//用OutWidth是因为OutWidth!=tempWidth
				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*MAINWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				*(image_out + tempaliadst) = tempyy1;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
				}

				break;

			case 2:

				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);

				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);
				x2 = *(LUTx2 + tempalia);
				y2 = *(LUTy2 + tempalia);

				kk1 = *(LUTk1 + tempalia);

				k1 = LUTK[kk1];

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*MAINWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*MAINWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);

				*(image_out + tempaliadst ) = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempv1*k1 + tempv2*(128-k1))>>7;
				}

				break;

			case 3:
				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);
				p3 = *(LUTp3 + tempalia);
				p4 = *(LUTp4 + tempalia);

				x1 = *(LUTx1 + tempalia);
				y1 = *(LUTy1 + tempalia);
				x2 = *(LUTx2 + tempalia);
				y2 = *(LUTy2 + tempalia);
				x3 = *(LUTx3 + tempalia);
				y3 = *(LUTy3 + tempalia);
				x4 = *(LUTx4 + tempalia);
				y4 = *(LUTy4 + tempalia);

				kk1 = *(LUTk1 + tempalia);
				kk2 = *(LUTk2 + tempalia);
				kk3 = *(LUTk3 + tempalia);  

				k1 = LUTK[kk1];
				k2 = LUTK[kk2];
				k3 = LUTK[kk3];

				if (p3==-1)
				{
					p3 = p4;
					x3 = x4;
					y3 = y4;
				}
				else if (p2==-1)
				{
					tempp1 = p1;
					tempx1 = x1;
					tempy1 = y1;

					p1 = p3;
					x1 = x3;
					y1 = y3;

					p2 = p4;
					x2 = x4;
					y2 = y4;

					p3 = tempp1;
					x3 = tempx1;
					y3 = tempy1;

					k1 = k2;
					k3 = 128 - k3;				
				}

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*MAINWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*MAINWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);

				tempyuv1 = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				tempyuv2 = *(image_in[p3] + y3*tempinitwidthStep + x3 );
				Yadjust3 = *(YadjustData+y3*MAINWIDTH+x3);
				tempyuv2 = MIN(255,tempyuv2*Yadjust3>>7);

				*(image_out + tempaliadst ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;
					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempyuv2 = *(image_in[p3] + pre_wh_U + (y3/2)*initWidth_half + x3/2 );

					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;

					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempv1*k1 + tempv2*(128-k1))>>7;
					tempyuv2 = *(image_in[p3] + pre_wh_V + (y3/2)*initWidth_half + x3/2 );

					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;
				}

				break;
			case 4:

				p1 = *(LUTp1 + tempalia);
				p2 = *(LUTp2 + tempalia);
				p3 = *(LUTp3 + tempalia);
				p4 = *(LUTp4 + tempalia);

				x1 = *(LUTx1 + tempalia) ;
				y1 = *(LUTy1 + tempalia) ;
				x2 = *(LUTx2 + tempalia) ;
				y2 = *(LUTy2 + tempalia) ;
				x3 = *(LUTx3 + tempalia) ;
				y3 = *(LUTy3 + tempalia) ;
				x4 = *(LUTx4 + tempalia) ;
				y4 = *(LUTy4 + tempalia) ;

				kk1 = *(LUTk1 + tempalia);
				kk2 = *(LUTk2 + tempalia);  
				kk3 = *(LUTk3 + tempalia);  

				k1 = LUTK[kk1];
				k2 = LUTK[kk2];
				k3 = LUTK[kk3];

				tempyy1 = *(image_in[p1] + y1*tempinitwidthStep + x1 );
				Yadjust1 = *(YadjustData+y1*MAINWIDTH+x1);
				tempyy1 = MIN(255,tempyy1*Yadjust1>>7);

				tempyy2 = *(image_in[p2] + y2*tempinitwidthStep + x2 );
				Yadjust2 = *(YadjustData+y2*MAINWIDTH+x2);
				tempyy2 = MIN(255,tempyy2*Yadjust2>>7);

				tempyuv1 = (tempyy1*k1 + tempyy2*(128-k1))>>7;

				tempyy3 = *(image_in[p3] + y3*tempinitwidthStep + x3 );
				Yadjust3 = *(YadjustData+y3*MAINWIDTH+x3);
				tempyy3 = MIN(255,tempyy3*Yadjust3>>7);
				tempyy4 = *(image_in[p4] + y4*tempinitwidthStep + x4 );
				Yadjust4 = *(YadjustData+y4*MAINWIDTH+x4);
				tempyy4 = MIN(255,tempyy4*Yadjust4>>7);



				tempyuv2 = (tempyy3*k2 + tempyy4*(128-k2))>>7;
				*(image_out + tempaliadst ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7 ;

				if (i%2 == 0 && j%2 ==0)
				{
					ii = i/2;
					jj = j/2;

					tempu1 = *(image_in[p1] + pre_wh_U + (y1/2)*initWidth_half + x1/2 );
					tempu2 = *(image_in[p2] + pre_wh_U + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempu1*k1 + tempu2*(128-k1))>>7;
					tempu3 = *(image_in[p3] + pre_wh_U + (y3/2)*initWidth_half + x3/2 );
					tempu4 = *(image_in[p4] + pre_wh_U + (y4/2)*initWidth_half + x4/2 );
					tempyuv2 = (tempu3*k1 + tempu4*(128-k1))>>7;
					*(image_out + pre_WH_U + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;

					tempv1 = *(image_in[p1] + pre_wh_V + (y1/2)*initWidth_half + x1/2 );
					tempv2 = *(image_in[p2] + pre_wh_V + (y2/2)*initWidth_half + x2/2 );
					tempyuv1 = (tempv1*k1 + tempv2*(128-k1))>>7;
					tempv3 = *(image_in[p3] + pre_wh_V + (y3/2)*initWidth_half + x3/2 );
					tempv4 = *(image_in[p4] + pre_wh_V + (y4/2)*initWidth_half + x4/2 );
					tempyuv2 = (tempv3*k1 + tempv4*(128-k1))>>7;
					*(image_out + pre_WH_V + ii*tempWidth_half + jj ) = (tempyuv1 * k3 + tempyuv2 * (128-k3))>>7;
				}

				break;
			}
		}
	}



	return 0;
}
///\寻找AOI点对应的主码流帧对应的阵列位置
 void MagixoomIPC::MagGMIPC_GetCamera(LutData FullLut,char *pIntPic,TyPoint AOIPoint)
 {
 	
	//新算法
	 int i;
	 int j;
	 int k;
	 int Wstep = MAINWIDTH/2;
	 int Hstep = MAINHEIGHT/2;
	 unsigned char numOverlapCurrent;
	 char p1 = -1;
	 char p2 = -1;
	 char p3 = -1;
	 char p4 = -1;
	 unsigned char *pOverlap = FullLut.pNumOverlap;

	 if (AOIPoint.x < Wstep)
	 {
		 AOIPoint.x = Wstep;
	 }
	 if (AOIPoint.x > FullWidth-Wstep-1)
	 {
		 AOIPoint.x = MAX(0,FullWidth-Wstep-1);
	 }

	 if (AOIPoint.y < Hstep)
	 {
		 AOIPoint.y = Hstep;
	 }
	 if (AOIPoint.y > FullHeight-Hstep-1)
	 {
		 AOIPoint.y = MAX(0,FullHeight-Hstep-1);
	 }



// 	 AOIPoint.x = MAX(Wstep,AOIPoint.x);
// 	 AOIPoint.x = MIN(FullWidth-Wstep,AOIPoint.x);
// 
// 	 AOIPoint.y = MAX(Hstep,AOIPoint.y);
// 	 AOIPoint.y = MIN(FullHeight-Hstep,AOIPoint.y);

	 for (i=AOIPoint.y - Hstep;i<AOIPoint.y + Hstep+1;i+=Hstep )
	 {
		 for (j = AOIPoint.x - Wstep;j < AOIPoint.x + Wstep+1; j += Wstep)
		 {

			 numOverlapCurrent = *(pOverlap + i * FullWidth + j);

			 switch(numOverlapCurrent)
			 {
			 case 1:
				 p1 = *(FullLut.p1 + i * FullWidth + j);
				 if (p1 != -1)
				 {
					 pIntPic[p1] = 1;
				 }
				 break;

			 case 2:
				 p1 = *(FullLut.p1 + i * FullWidth + j);
				 p2 = *(FullLut.p2 + i * FullWidth + j);
				 if (p1 != -1)
				 {
					 pIntPic[p1] = 1;
				 }
				 if (p2 != -1)
				 {
					 pIntPic[p2] = 1;
				 }

				 break;

			 case 3:
				 p1 = *(FullLut.p1 + i * FullWidth + j);
				 p2 = *(FullLut.p2 + i * FullWidth + j);
				 p3 = *(FullLut.p3 + i * FullWidth + j);
				 p4 = *(FullLut.p4 + i * FullWidth + j);

				 if (p1 != -1)
				 {
					 pIntPic[p1] = 1;
				 }
				 if (p2 != -1)
				 {
					 pIntPic[p2] = 1;
				 }
				 if (p3 != -1)
				 {
					 pIntPic[p3] = 1;
				 }
				 if (p4 != -1)
				 {
					 pIntPic[p4] = 1;
				 }

				 break;

			 case 4:
				 p1 = *(FullLut.p1 + i * FullWidth + j);
				 p2 = *(FullLut.p2 + i * FullWidth + j);
				 p3 = *(FullLut.p3 + i * FullWidth + j);
				 p4 = *(FullLut.p4 + i * FullWidth + j);
				 if (p1 != -1)
				 {
					 pIntPic[p1] = 1;
				 }
				 if (p2 != -1)
				 {
					 pIntPic[p2] = 1;
				 }
				 if (p3 != -1)
				 {
					 pIntPic[p3] = 1;
				 }
				 if (p4 != -1)
				 {
					 pIntPic[p4] = 1;
				 }

				 break;
			 }

		 }
	 }
 
 	return;
 }
