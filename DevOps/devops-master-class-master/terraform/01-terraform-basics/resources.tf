# Configure s3 bucket
resource "aws_s3_bucket" "my_s3_bucket" {
    bucket = "my-s3-bucket-barup-001"
}

# Versioning for s3 bucket
resource "aws_s3_bucket_versioning" "versioning_example" {
  bucket = aws_s3_bucket.my_s3_bucket.id
  versioning_configuration {
    status = "Enabled"
  }
}

# Variable
variable "iam_user_name_prefix" {
  default = "my_iam_user"
}

# User creation
resource "aws_iam_user" "my_iam_user" {
    count = 3
    name = "${var.iam_user_name_prefix}_${count.index}"
}
