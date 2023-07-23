FROM --platform=${TARGETPLATFORM:-linux/amd64} ghcr.io/openfaas/classic-watchdog:0.2.2 as watchdog

# Build Stage
FROM alpine:latest as builder

RUN apk --no-cache add g++


RUN USER=root
WORKDIR /usr/src/function
COPY main.cpp .

RUN g++ -c handler.cpp -o handler.o
RUN g++ main.cpp handler.o -o main

#RUN g++ -o main main.cpp

# Runner stage
FROM alpine:latest as runner 

COPY --from=watchdog /fwatchdog /usr/bin/fwatchdog
RUN chmod +x /usr/bin/fwatchdog

WORKDIR /usr/src/function

COPY --from=builder /usr/src/function/main .

ENV fprocess="main"

RUN ls -la /

CMD ["fwatchdog"]
