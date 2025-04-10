# TODO

168: 数学公式

340：最短路+二分答案

342： 

# 搜索

## BFS

### 179. 八数码

x左右移动时不会改变逆序对数量，上下移动时会改变两个，最终状态没有逆序对，因此如果初始状态逆序对为奇数，则无解。



## DFS

剪枝：

> 1. 优化搜索顺序, 减少分支
> 2. 排除等效冗余
> 3. 可行性剪枝

### 180 排书

估价函数：排好的序列每一处都是连续的：i后面一定是i+1，用tot代表当前序列不连续处总和，每次交换最优情况下可以改正三处不连续的，因此离操作成功还需要的最小步数为tot/3，向上取整

---

x,y双指针分别代表换之前和换之后

先让x从r+1走到k，在从l走到r

y一直走就行

![image-20250305163325651](C:\Users\18268\AppData\Roaming\Typora\typora-user-images\image-20250305163325651.png)



# 图论

dijstra是用最短的边去更新其他边，而spfa是上次更新的终点去更新其他边

Dijkstra-朴素O(n^2)

1. 初始化距离数组, dist[1] = 0, dist[i] = inf;

2. for n次循环 每次循环确定一个min加入S集合中，n次之后就得出所有的最短距离
3. 将不在S中dist_min的点->t
4. t->S加入最短路集合
5. 用t更新到其他点的距离

Dijkstra-堆优化O(mlogm)

1. 利用邻接表，优先队列
2. 在priority_queue<PII,vector<PII>,greater<PII>> heap;中将返回堆顶
3. 利用堆顶来更新其他点，并加入堆中类似宽搜

Bellman_fordO(nm)

1. 注意连锁想象需要备份, struct Edge{int a,b,c} Edge[M];

2. 初始化dist, 松弛dist[x.b] = min(dist[x.b], backup[x.a]+x.w);
3. 松弛k次，每次访问m条边

Spfa O(n)~O(nm)

1. 利用队列优化仅加入修改过的地方

2. for k次
3. for 所有边利用宽搜模型去优化bellman_ford算法
4. 更新队列中当前点的所有出边

Floyd O(n^3)

1. 初始化d

2. k, i, j 去更新d

## 单源图最短路建图

### 建图

点也有权值：建一个虚拟源点，链接各点 [903](#903)

#### 邻接表

e 数组下标表示第几条边（idx）

e数组值表示哪个点（12345...n）

``` cpp
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
```

### 903

酋长的rank不一定是最大的，所以要遍历 (rank[1]-m,rank[1]+m) 区间

![image-20250406161852601](C:\Users\18268\AppData\Roaming\Typora\typora-user-images\image-20250406161852601.png)



## 单源最短路应用（+其他算法）

### 1135

先dijstra预处理6个点，再dfs枚举搜索顺序

### 341

![image-20250408011544246](C:\Users\18268\AppData\Roaming\Typora\typora-user-images\image-20250408011544246.png)

## 单源最短路扩展

### 1137

反向建图/虚拟源点

## Floyd

### 1125

求：连上这条路径后，所有牧场（生成的新牧场和原有牧场）中**直径最大的牧场的直径尽可能小。**

1. 先floyd预处理出任意两点间最短路

2. 求出直径最大的牧场的直径

假设连边之后的牧场的直径最大， 最大直径为：

```
maxd[i] + maxd[j] + get_d(q[i], q[j])
```

3. 再求出这个直径的最小值

```
 r2 = min(r2, maxd[i] + maxd[j] + get_d(q[i], q[j]))
```

但最大直径也可能是没连边之前，各个连通块内直径最大值

```
maxd[i] = max(maxd[i], d[i][j]);
r1 = max(r1, maxd[i]);
```

为了确保答案是最大直径

```
ans = max(r1,r2)
```

### 343

![image-20250410000803023](C:\Users\18268\AppData\Roaming\Typora\typora-user-images\image-20250410000803023.png)



# DONE

### 871 约数之和

![image-20240929162728576](C:\Users\18268\AppData\Roaming\Typora\typora-user-images\image-20240929162728576.png)

### 873 欧拉函数

![image-20241002153143184](C:\Users\18268\AppData\Roaming\Typora\typora-user-images\image-20241002153143184.png)



