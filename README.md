# last-work 绝对防御
 雷达监控报警器
 
## 1材料 
arduino uno板子一块 
超声波测距模块一个
RGB灯一个
小型舵机一个 
杜邦线若干


## 2创作灵感
喜欢军事塔防游戏，于是想做一个雷达监控报警器，在网上查找相关资料后，开始制作。


## 3主要用途
可以用于房门防护，警务亭，等一系列需要防护与监控的地方


## 3组装图
![ii](https://github.com/hujunbao718/last-work/blob/master/big%20work%20%E7%BB%9D%E5%AF%B9%E9%98%B2%E5%BE%A1_bb.jpg)


## 4实物图
![ii](https://github.com/hujunbao718/last-work/blob/master/IMG_20170702_234427.jpg)


## 5原理
 在arduino里 控制舵机。从0度 到180度。每次增加1度角度 如果当前角度到了180度。则从下次开始。每次角度减1 
效果就是 舵机从左向右慢慢旋转、转到右侧、再从右侧慢慢向左旋转。
流程是 改变舵机角度 +-1度 -> 超声波测距 -> 像串口发送当前的角度和超声波测距得到的距离。 角度是从0~180度 距离是从 2~ 300~400 厘米(cm) 左右 这个要看具体的超声波测距模块的参数。

在不同距离时RGB灯亮不同颜色，远距离蓝灯亮，近距离红灯亮，没有物体接近绿灯亮。

processing 接受到串口的数据。解析出来角度和距离。 将这个数据。放入数组中的对应角度下标值为这个角度的距离。

然后processing每次循环。都重新绘制界面。绘制当前角度的扫描扇形 取出数组中所有的数据。 再转换一下比例。再计算一下障碍物的坐标。绘制障碍物。


## 6效果图
![ii](https://github.com/hujunbao718/last-work/blob/master/big%20work.png)
![ii](https://github.com/hujunbao718/last-work/blob/master/IMG_20170702_231520.JPG)
![ii](https://github.com/hujunbao718/last-work/blob/master/IMG_20170702_231549.JPG)
![ii](https://github.com/hujunbao718/last-work/blob/master/IMG_20170702_231611.JPG)

## 7视频链接
http://pan.baidu.com/s/1eRYfECy

## 8Arduino源代码
https://github.com/hujunbao718/last-work/blob/master/big_work______processing.pde

## 9Processing源代码
