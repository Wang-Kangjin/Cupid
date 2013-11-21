                          丘比特神箭项目
    linux命令行环境下实现的一个小动画，两个心逐渐靠近，重叠在一起，然后一只箭穿过去，很简单，很有趣哦。
    使用方法（运行时需要窗口最大化，不然会换行）：
         1）make
         2）./cupid
    实现方法：
        每颗心都是一个数组，每次把他们添加到一个更大的数组中的不同位置，实现移动的效果。箭也一样。基本思想就是这样。
    重叠时的解决方法（添加过程其实就是数组拷贝过程，一个点一个点进行拷贝）：
        由于每个心都是int 型数组，数值就代表了颜色，0代表无色。对于大面板中值是0的点，则把心的那个点填进去（覆盖透明的点）；对于非0点，不填；这样就可以作出重叠效果。
    然后就是添加箭了，它也是数组，它一半要覆盖在一个心的上面，并且另一半被另外一个心覆盖，更有层次感。但难度也加大，我的解决办法：
        添加心时，把两个心的重叠区域的值乘100，这样，如果在添加箭的过程中，碰到属于第一个心的点就覆盖上去，碰到大于100或者属于第二个心的点就不添加（做到被第二个心覆盖的效果）。乘100也是为了更好的扩展性，我们肯定不会有超过100种颜色。
    最后显示大数组（面板），做一个颜色映射，比如：1->红色; 2->蓝色...等等，碰到大于100的，除以100再做映射。
    我理解到代码风格的重要性了，我写的代码放上来都有点不好意思，以后写代码，遵循规范，注释，文档也要规范。

email: kangjin.wang@gmail.com
name:王康瑾