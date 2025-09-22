仓库中有两个版本的原码，他们只在最后的输出和半径限制上不同，因为输出的原因，有时候圆形看起来像一个上下长，左右窄的椭圆，我在其中加入了空格来改善，但是也限制了每行的输出个数。

当然，本人实力有限，一些边界问题还没有得到妥善解决，仅供大家娱乐，如果有大佬能完善此代码，本人不胜感激。
# 方格纸绘制近似圆形的方法

如何在一张方格纸上画出一个比较接近圆形的圆？这个问题是我在玩Minecraft的时候想到的（只是想给我的信标上方加一个星环状的结构），所以用大概半个下午的时间编写了这个程序。只需要运行然后输入相应圆的半径，就可以根据我写的搜索+贪心算法和可视化输出展示出圆形。。

## 算法原理

算法很简单，核心逻辑是从圆的一边开始沿半径顺时针搜索，并且以圆心为原点划分出四个象限，规定搜索点在特定象限里只能往特定方向移动（比如第一象限只能向右或向下），并且计算周围格子距离圆心的举例，选择跟半径相近的那个。

## 移动控制数组

以下是我用来控制移动的数组，可以看前后有重复的地方，因为我不想到了数组尾再跳到开头，所以就把开头部分复制了到了末尾

```c
mo[2][10]={
    {-1,-1,-1,0,1,1,1,0,-1,-1},//x
    {-1,0,1,1,1,0,-1,-1,-1,0},//y
};
```

## 两个文件
仓库中有两个版本的原码，他们只在最后的输出和半径限制上不同，因为输出的原因，有时候圆形看起来像一个上下长，左右窄的椭圆，我在其中加入了空格来改善，但是也限制了每行的输出个数。

## 最后的话
当然，本人实力有限，一些边界问题还没有得到妥善解决，仅供大家娱乐，如果有大佬能完善此代码，本人不胜感激。




# Method for Drawing an Approximate Circle on Graph Paper  

## Background  
How to draw a circle close to a perfect circle on graph paper? This idea came to me while playing Minecraft (I wanted to add a star-ring structure above the beacon), so I spent about half an afternoon writing this program. Just run it, enter the radius of the circle, and the search+greedy algorithm with visual output will display the circle.  


## Algorithm Principle  
The algorithm is simple. The core logic is to start searching clockwise along the radius from one side of the circle, divide the plane into four quadrants with the center as the origin, specify that the search point can only move in specific directions within a quadrant (e.g., only right or down in the first quadrant), and calculate the distance from surrounding grids to the center to select the one closest to the radius.  


## Movement Control Array  
The following is the array used to control movement (note the repeated segments at the beginning and end, which avoid jumping from the end of the array back to the start):  

```c
mo[2][10]={
    {-1,-1,-1,0,1,1,1,0,-1,-1},//x-direction movement
    {-1,0,1,1,1,0,-1,-1,-1,0},//y-direction movement
};
```
## Two Versions  
There are two versions of the source code in the repository. They only differ in the final output format and radius constraints. Due to output limitations, the circle sometimes appears as a vertically elongated and horizontally narrow ellipse. I added spaces to improve the appearance, but this also restricts the number of characters per line.  


## Final Words  
Of course, due to my limited capabilities, some boundary issues have not been properly resolved. This is for entertainment purposes only. If any experts can improve this code, I would be extremely grateful.
