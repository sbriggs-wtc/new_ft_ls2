FROM debian
LABEL maintainer="sbriggs"
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y build-essential -y valgrind

RUN mkdir /ft_ls && \
    ln -s my_link.txt my_link.txt

WORKDIR /ft_ls
ENTRYPOINT /bin/bash

#RUN apt-get install --yes vim gcc git make 
#ADD ./copy_by_dockerfile /copy_by_dockerfile
#CMD /bin/bash
#apt-get install -y --no-install-recommends \
#apt-cache search valgrind
#docker run -it --rm --mount type=bind,source=D:\Users\briggss\Desktop\docker,destination=/shaneWorkspace --name ft-ls-container debian_c
#valgrind --leak-check=full ./ft_ls
#(you can add -v)
#cd "C:\Program Files\Docker\Docker" ./DockerCli.exe -SwitchDaemon //this is for switching between linux and windows containers on a windows machine.
#if there is a clockskew,  restart docker
#./ft_ls -l | wc -l
#(this doesnt work)docker run -it --rm --mount type=bind,source=${PWD}/ft_ls,destination=/ft_ls --name ft-ls debian_c
#docker stop $(docker ps -a -q) && docker rm $(docker ps -a -q) && docker ps -a
#docker rm $(docker ps -a -q)
#docker exec -it ft-ls bash


#BUILD CONTAINER LIKE THIS:
#docker build --tag debian_c .
#docker run -it --rm --name foobar debian_c

#CHANGE THE EXAMPLE "source" DIRECTORY AND RUN LIKE THIS:
#docker run -it --rm --mount type=bind,source=/d/Users/briggss/Desktop/new_ft_ls2/ft_ls,destination=/ft_ls --name ft-ls debian_c

#TEST MEMORY LEAKS LIKE THIS:
#valgrind --leak-check=full ./ft_ls