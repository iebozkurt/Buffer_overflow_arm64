FROM fedora:29



RUN dnf install -y zsh gcc libtool glibc-devel iputils net-tools util-linux-user vim wget gdb

RUN useradd student
RUN chown -R student:student /home/student
RUN echo "student:password" | chpasswd
RUN echo "root:password" | chpasswd

ADD ./c_programs  /home/student/

