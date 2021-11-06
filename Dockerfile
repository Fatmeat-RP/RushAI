
################################################
#                    BUILD                     #
################################################

FROM archlinux:latest as builder

RUN yes | pacman -Syu git make sudo

WORKDIR /build

COPY . .

RUN make -C /setup


###############################################
#                    RUN                      #
###############################################


FROM archlinux:latest

WORKDIR /app

RUN yes | pacman -Syu git make

RUN useradd -G wheel chucknorris && chown -R chucknorris /app

USER chucknorris

COPY --from=builder /build/* /app/player

CMD ./chucknorris
