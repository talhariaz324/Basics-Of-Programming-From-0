/*
Elements are:
1) Messgae Encoding ==> Messgae encoding mean when computer wants to access server of amazon. its data changes into signal if transmission
medium is wire and into waves if transmission medium is wireless. And suppose after wireless medium router has wired medium then waves converted into signal. Thats all about encoding

2) Message formating and encapsulation ==> Message formating in such a way which is understandable by the source and destination only.
Data also contain the IP address of the source and destination by which intermediary forward it to its destination.

3) Messgae Timing ==>  In case source is fast and destination is slow then it may not recieve data. Message timing should be equal
 to the speed of reciver, protocols ensure the speed of reciver and then tell to source to send the data of that particular amount. 

4) Messge Size ==> Message or data can be very big but the capacity of transmission medium is small. So message is divided into small
 segments and transfer. But it may cause difficulty to destination to understand which packet is to where to place for combining and 
 get whole data. So for fixing it source give sequential numbers to the segments and reciever make whole msg with help of these numbers.
 
5) Messgage Delivery Options ==> Message delivery option is to whom deliver data. it can be one (uni cast). it can multiple but not all in network (multi cast). it can be all (broadcast)
*/