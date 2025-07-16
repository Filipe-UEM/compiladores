; ModuleID = 'MinhaLinguagem'
source_filename = "MinhaLinguagem"

declare i32 @printf(ptr, ...)

declare i32 @scanf(ptr, ...)

declare ptr @malloc(i32)

declare i32 @putchar(i8)

define i32 @main() {
entry:
  ret i32 0
}
