//
//                                                          _ooOoo_
//                                                         o8888888o
//                                                         88" . "88
//                                                         (| -_- |)
//                                                          O\ = /O
//                                                      ____/`---'\____
//                                                    .   ' \\| |// `.
//                                                     / \\||| : |||// \
//                                                   / _||||| -:- |||||- \
//                                                     | | \\\ - /// | |
//                                                   | \_| ''\---/'' | |
//                                                    \ .-\__ `-` ___/-. /
//                                                 ___`. .' /--.--\ `. . __
//                                              ."" '< `.___\_<|>_/___.' >'"".
//                                             | | : `- \`.;`\ _ /`;.`/ - ` : | |
//                                               \ \ `-. \_ __\ /__ _/ .-` / /
//                                       ======`-.____`-.___\_____/___.-`____.-'======
//                                                          `=---='
//
//                                       .............................................
//                                              ���汣��             ����BUG
//                                      ��Ի:
//                                              д��¥��д�ּ䣬д�ּ������Ա��
//                                              ������Աд�������ó��򻻾�Ǯ��
//                                              ����ֻ���������������������ߣ�
//                                              ��������ո��գ����������긴�ꡣ
//                                              ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
//                                              ���۱������Ȥ���������г���Ա��
//                                              ����Ц��߯��񲣬��Ц�Լ���̫����
//                                              ��������Ư���ã��ĸ���ó���Ա��

#include<stdio.h>
#include<string.h>
#include "joy.h"
void PrintCenterAlign(char *pStr, int Len)
{
	int lSpaceNum = (Len - strlen(pStr)) / 2;
	printf("%*s\n", lSpaceNum + strlen(pStr), pStr);
}

void PrintGodBless(void)
{
	int pos = 120;
	printf("\n");
	PrintCenterAlign("_ooOoo_", pos);
	PrintCenterAlign("o8888888o", pos);
	PrintCenterAlign("88\" . \"88", pos);
	PrintCenterAlign("(| -_- |)", pos);
	PrintCenterAlign("O\\ = /O", pos);
	PrintCenterAlign("____/'---'\\____", pos);
	PrintCenterAlign(".' \\\\| |// '.", pos);
	PrintCenterAlign("/ \\\\||| : |||// \\", pos);
	PrintCenterAlign("/ _||||| -:- |||||- \\", pos);
	PrintCenterAlign("| | \\\\\\ - /// | |", pos);
	PrintCenterAlign("| \\_| ''\\---/'' |_/", pos);
	PrintCenterAlign("\\ .-\\__ `-` ___/-. /", pos);
	PrintCenterAlign("___`. .' /--.--\\ `. . __", pos);
	PrintCenterAlign(".\"\" '< `.___\\_<|>_/___.' >'\"\".", pos);
	PrintCenterAlign("| | : `- \\`.;`\\ _ /`;.`/ - ` : | |", pos);
	PrintCenterAlign("\\ \\ `-. \\_ __\\ /__ _/ .-` / /", pos);
	PrintCenterAlign("======`-.____`-.___\\_____/___.-`____.-'======", pos);
	PrintCenterAlign("`=---='", pos);
	printf("\n");
	PrintCenterAlign("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^", pos);
	PrintCenterAlign("  *God Bless          Never Crash* ", pos);
	printf("\n");
}

