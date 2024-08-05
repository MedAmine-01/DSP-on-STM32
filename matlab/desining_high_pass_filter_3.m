clc;
workspace;

format long g;
format compact;

frontSize=2;

t=0:1/2000:0.5;

f1=10;
t1=1/f1;
amp1=1;
signal1= amp1 * sin(2*pi*f1*t);

subplot(4,1,1)
plot(t,signal1)

f2=100;
t2=1/f2;
amp2=1;
signal2= amp2 * sin(2*pi*f2*t);

subplot(4,1,2)
plot(t,signal2)

f3=500;
t3=1/f3;
amp3=1;
signal3= amp3 * sin(2*pi*f3*t);

subplot(4,1,3)
plot(t,signal3)

signal = signal1+signal2+signal3;

subplot(4,1,4)
plot(t,signal)

%cuttoff frequency
fc=400;
%sampling frequency
fs=2000;
%fc/fs is the normalized cuttoff frequency
h=fir1(100,fc/fs,'high');

plot(h);
freqz(h);
 
filtered_signal= conv(h,signal);
subplot(3,1,1)
plot(signal)
title('Input signal')

subplot(3,1,2)
plot(filtered_signal)
title('filtered signal')

subplot(3,1,3)
plot(signal3)
title('original 500hz signal')

csvwrite('hpf_fc_400hz.txt',h);


