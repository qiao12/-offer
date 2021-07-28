#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
typedef struct Bbox {
	int x;
	int y;
	int w;
	int h;
	float score;
}Bbox;
bool sort_score(Bbox box1, Bbox box2) {
	return (box1.score > box2.score);
}
float iou(Bbox box1, Bbox box2) {
	int x1 = max(box1.x, box2.x);
	int y1 = max(box1.y, box2.y);
	int x2 = min((box1.x + box1.w), (box2.x + box2.w));
	int y2 = min((box1.y + box1.h), (box2.y + box2.h));
	int w = x2 - x1;
	int h = y2 - y1;
	if (w <= 0 || h <= 0)
	{
		return 0.0;
	}
	float over_area = w * h;
	float iou = over_area / (box1.w * box1.h + box2.w * box2.h - over_area);
	return iou;
}



vector<Bbox> nms(vector<Bbox>& vec_boxs, float threshold) {
	sort(vec_boxs.begin(), vec_boxs.end(), sort_score);
	int n = vec_boxs.size();
	vector<bool> del(n, false);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			float iou_value = iou(vec_boxs[i], vec_boxs[j]);
			if (iou_value > threshold)
			{
				del[j] = true;
			}
		}
	}
	vector<Bbox> result;
	for (auto i:del)
	{
		if (!del[i]) result.push_back(vec_boxs[i]);
	}
	return result;
}

