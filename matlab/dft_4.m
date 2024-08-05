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
stem(t,signal)

signal_fft=fft(signal);
l=length(signal);
sig_max= abs(signal_fft);

fs=2000;
f=fs*(0:(l/2))/l;


p2= abs(signal_fft/l)
p1=p2(1: l/2+1)
p1(2:end-1)=2*p1(2:end-1)


plot(f,p1);
title('signle sided Amplitute spectrum of x(t)');
xlabel('f(Hz)')

