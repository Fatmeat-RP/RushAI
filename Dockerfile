FROM archlinux:latest as builder

RUN pacman -Syu gcc base-devel make

WORKDIR /build

COPY . .

RUN make -C /setup

FROM debian:10-slim

WORKDIR /app

RUN usermod -G wheel fatmeat && chown -R fatmeat /app

USER player

COPY --from=builder /build/* /app/player
