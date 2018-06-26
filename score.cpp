#include "score.h"
#include "Number.h"

void DrawScore(int score, int dig, bool bZero, float x, float y)
{
	int maxscore = 10;
	for (int i = 1; i < dig; i++)
	{
		maxscore *= 10;
	}
	maxscore--;

	if (score>maxscore)
	{
		score = maxscore;
	}

	////ç∂ãlÇﬂ
	//if (dig <= 0)
	//{
	//	dig = 1;
	//	for (;;)
	//	{
	//		score /= 10;
	//		if (score == 0)
	//		{
	//			break;
	//		}
	//		dig++;
	//	}
	//}

	for (int i = dig-1; i >= 0; i--)
	{
		int n = score%10;
		score /= 10;
		DrawNumber(n, x +i* NUMBER_WIDTH*2, y);
		if (!bZero&& (score /= 10) == 0)
		{
			break;
		}
	}

}