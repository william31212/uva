#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("uva12694.in","r",stdin);
	freopen("uva12694.out","w",stdout);
	#endif

	vector< pair<int,int> > meeting;
	int times;
	scanf("%d",&times);


	while(times--)
	{
		meeting.clear();
		int end_time,start_time;

		while(scanf("%d %d",&start_time,&end_time) && (!!end_time || !!start_time))
		{
			meeting.push_back(make_pair(end_time,start_time));


		}
		sort(meeting.begin(),meeting.end());
		// for (int i = 0; i < meeting.size(); ++i)
		// {
		// 	printf("%d %d\n", meeting[i].first, meeting[i].second);
		// }

		int used = 0;
		int cnt = 0;
		for (int i = 0; i < meeting.size(); ++i)
		{
			if (meeting[i].second >= used)
			{
				used = meeting[i].first;
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}