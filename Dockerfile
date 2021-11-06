
################################################
#                    BUILD                     #
################################################

FROM archlinux:latest as builder

RUN yes | pacman -Syu base-devel

WORKDIR /build

COPY . .

RUN make -C /setup


###############################################
#                    RUN                      #
###############################################


FROM archlinux:latest

WORKDIR /app

RUN useradd chucknorris && chown -R chucknorris /app

USER chucknorris

COPY --from=builder /build/* /app/player

RUN yes | pacman -Syu base-devel

CMD ./chucknorris
