
################################################
#                    BUILD                     #
################################################

FROM archlinux:latest

RUN pacman -Syu gcc base-devel make

WORKDIR /build

COPY . .

RUN make -C /setup


###############################################
#                    RUN                      #
###############################################


FROM archlinux:latest

WORKDIR /app

RUN usermod -G wheel fatmeat && chown -R fatmeat /app

USER fatmeat

COPY --from=builder /build/* /app/player

RUN pacman -Syu gcc base-devel make

cmd make | ./player
