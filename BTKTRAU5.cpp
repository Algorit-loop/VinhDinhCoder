#include <bits/stdc++.h>
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
#include <bits/stdc++.h>

using namespace std;
long long sum1 , sum2 ,res = 0 ;
int a[30],b[30],c[30];
int n,k=0;
unordered_map<long long,long long> mymap;
void ql(int x)
{
    for (int i=1; i<=3; i++)
    {
        if (i == 1) sum1 = sum1 + a[x];
        if (i == 2) sum2 = sum2 + a[x];
        if (x < n/2) ql(x + 1);
        if (x == n/2)
        {
            mymap[sum1-sum2] = max(mymap[sum1-sum2],sum1+sum2);
        }
        if (i == 1) sum1 = sum1 - a[x];
        if (i == 2) sum2 = sum2 - a[x];
    }
}
void _check(int x)
{
    for (int i=1; i<=3; i++)
    {
        if (i == 1) sum1 = sum1 + b[x];
        if (i == 2) sum2 = sum2 + b[x];
        if (x < k) _check(x+1);
        if (x == k)
        {
            if (mymap.count(sum2-sum1) > 0)
                res = max(res ,(sum1 + sum2 + mymap[sum2-sum1])/2);
        }
        if (i == 1) sum1 = sum1 - b[x];
        if (i == 2) sum2 = sum2 - b[x];
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> c[i];
    for (int i=1; i<=n/2; i++)
        a[i] = c[i];
    for (int i=n/2+1; i<=n; i++) b[++k] = c[i];
    sum1 = 0; sum2 = 0;
    ql(1);
    //for (auto u : mymap) cout << u.first << " " << u.second <<"\n";
    sum1 = 0; sum2 = 0;
    _check(1);
    cout << res;
    return 0;
}
    
#include <bits/stdc++.h>

using namespace std;
long long sum1 , sum2 ,res = 0 ;
int a[30],b[30],c[30];
int n,k=0;
unordered_map<long long,long long> mymap;
void ql(int x)
{
    for (int i=1; i<=3; i++)
    {
        if (i == 1) sum1 = sum1 + a[x];
        if (i == 2) sum2 = sum2 + a[x];
        if (x < n/2) ql(x + 1);
        if (x == n/2)
        {
            mymap[sum1-sum2] = max(mymap[sum1-sum2],sum1+sum2);
        }
        if (i == 1) sum1 = sum1 - a[x];
        if (i == 2) sum2 = sum2 - a[x];
    }
}
void _check(int x)
{
    for (int i=1; i<=3; i++)
    {
        if (i == 1) sum1 = sum1 + b[x];
        if (i == 2) sum2 = sum2 + b[x];
        if (x < k) _check(x+1);
        if (x == k)
        {
            if (mymap.count(sum2-sum1) > 0)
                res = max(res ,(sum1 + sum2 + mymap[sum2-sum1])/2);
        }
        if (i == 1) sum1 = sum1 - b[x];
        if (i == 2) sum2 = sum2 - b[x];
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> c[i];
    for (int i=1; i<=n/2; i++)
        a[i] = c[i];
    for (int i=n/2+1; i<=n; i++) b[++k] = c[i];
    sum1 = 0; sum2 = 0;
    ql(1);
    //for (auto u : mymap) cout << u.first << " " << u.second <<"\n";
    sum1 = 0; sum2 = 0;
    _check(1);
    cout << res;
    return 0;
}
    
